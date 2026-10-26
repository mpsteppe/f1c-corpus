int __thiscall ArrayInitWithSentinelInLoop(_DWORD *this)
{
  _DWORD *v1; // ebx
  _BYTE *v2; // edi
  _DWORD *v3; // esi
  int v4; // ebp
  int result; // eax

  v1 = this + 4192;
  v2 = this + 229;
  v3 = this + 3974;
  v4 = 104;
  do
  {
    *v3 = -1;
    StructFieldZeroInitWithDefaults(v2);
    result = ThunkWithStructInitSubCalls(v1);
    ++v3;
    v2 += 140;
    v1 += 218;
    --v4;
  }
  while ( v4 );
  return result;
}
