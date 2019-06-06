// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

namespace nd4j.graph
{

using global::System;
using global::FlatBuffers;

public struct UIAddName : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static UIAddName GetRootAsUIAddName(ByteBuffer _bb) { return GetRootAsUIAddName(_bb, new UIAddName()); }
  public static UIAddName GetRootAsUIAddName(ByteBuffer _bb, UIAddName obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public void __init(int _i, ByteBuffer _bb) { __p.bb_pos = _i; __p.bb = _bb; }
  public UIAddName __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public int NameIdx { get { int o = __p.__offset(4); return o != 0 ? __p.bb.GetInt(o + __p.bb_pos) : (int)0; } }
  public string Name { get { int o = __p.__offset(6); return o != 0 ? __p.__string(o + __p.bb_pos) : null; } }
#if ENABLE_SPAN_T
  public Span<byte> GetNameBytes() { return __p.__vector_as_span(6); }
#else
  public ArraySegment<byte>? GetNameBytes() { return __p.__vector_as_arraysegment(6); }
#endif
  public byte[] GetNameArray() { return __p.__vector_as_array<byte>(6); }

  public static Offset<UIAddName> CreateUIAddName(FlatBufferBuilder builder,
      int nameIdx = 0,
      StringOffset nameOffset = default(StringOffset)) {
    builder.StartObject(2);
    UIAddName.AddName(builder, nameOffset);
    UIAddName.AddNameIdx(builder, nameIdx);
    return UIAddName.EndUIAddName(builder);
  }

  public static void StartUIAddName(FlatBufferBuilder builder) { builder.StartObject(2); }
  public static void AddNameIdx(FlatBufferBuilder builder, int nameIdx) { builder.AddInt(0, nameIdx, 0); }
  public static void AddName(FlatBufferBuilder builder, StringOffset nameOffset) { builder.AddOffset(1, nameOffset.Value, 0); }
  public static Offset<UIAddName> EndUIAddName(FlatBufferBuilder builder) {
    int o = builder.EndObject();
    return new Offset<UIAddName>(o);
  }
};


}
