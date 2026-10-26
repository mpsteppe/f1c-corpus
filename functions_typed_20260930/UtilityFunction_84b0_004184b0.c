int __thiscall UtilityFunction_84b0(int this)
{
  _DWORD *v2; // ecx
  int v3; // ecx
  int v4; // edx

  ShortArrayInit((_WORD *)this);
  v2 = (_DWORD *)(this + 2148);
  do
  {
    StructInitWithSentinelValues(v2);
    v2 = (_DWORD *)(v3 + 32);
  }
  while ( v4 != 1 );
  *(_BYTE *)(this + 2800) = 0;
  *(_DWORD *)(this + 2804) = 0;
  EmptyStub_0170();
  BufferInitWith10fDefaults((_DWORD *)this);
  return this;
}

