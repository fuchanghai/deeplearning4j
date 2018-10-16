/*******************************************************************************
 * Copyright (c) 2015-2018 Skymind, Inc.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Apache License, Version 2.0 which is available at
 * https://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 ******************************************************************************/

//
//  @author sgazeos@gmail.com
//  

#include <op_boilerplate.h>
#if NOT_EXCLUDED(OP_top_k)

//#include <ops/declarable/headers/parity_ops.h>
#include <ops/declarable/helpers/top_k.h>
#include <ops/declarable/CustomOperations.h>

namespace nd4j {
    namespace ops {
        CUSTOM_OP_IMPL(top_k, 1, 2, false, 0, -2) {
            auto x = INPUT_VARIABLE(0);
            int k = 1;// from params
            bool needSort = true;
            auto values = OUTPUT_VARIABLE(0);
            auto indeces = OUTPUT_VARIABLE(1);
            if (block.numI() > 0) {
                if (block.numI() > 1) {
                k = INT_ARG(0);
                needSort = INT_ARG(1);
                }
                else 
                    k = INT_ARG(0);
            }

            REQUIRE_TRUE(k <= x->sizeAt(-1), 0, "top_k: k should not be greater than last dimension");
            REQUIRE_TRUE(k >=0, 0, "top_k: k should be non-negative");

            int res =  helpers::topKFunctor(x, values, indeces, k, needSort);
            values->printIndexedBuffer("Values");
            indeces->printIndexedBuffer("Indeces");
            return res;
        }

        DECLARE_SHAPE_FN(top_k) {
            auto shapeList = SHAPELIST(); 
            auto in = inputShape->at(0);
            int shapeRank = shape::rank(in);
            int k = 1; // default output shape is size 1

            if (block.numI() > 0) {
                k = INT_ARG(0);
            }

            for (int e = 0; e < 2; e++) { // 2 element tuple at output
                Nd4jLong* aShape;
                ALLOCATE(aShape, block.getWorkspace(), shape::shapeInfoLength(shapeRank), Nd4jLong);
                aShape[0] = shapeRank;
                for (int i = 1 ; i < shapeRank; ++i)
                    aShape[i] = shape::sizeAt(in, i - 1);
                aShape[shapeRank] = k;

                shape::updateStrides(aShape, shape::order(in));
                ArrayOptions::setDataType(aShape, (e == 0?ArrayOptions::dataType(in):nd4j::DataType::INT64));
                shapeList->push_back(aShape);
            }
            return shapeList;
        }

        DECLARE_TYPES(top_k) {
            getOpDescriptor()
                    ->setAllowedInputTypes(nd4j::DataType::ANY)
                    ->setAllowedOutputTypes(0, nd4j::DataType::ANY)
                    ->setAllowedOutputTypes(1, {ALL_INTS});
        }
    }
}

#endif