char *__thiscall sub_4FC550(int this, char a2)
{
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *result; // eax
  int v7; // [esp+4h] [ebp-Ch] BYREF
  char *v8; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  v7 = 0;
  v8 = (char *)OperatorNewNhMallocWrapper(256);
  *v8 = 0;
  v3 = (char *)dword_5EC3D8;
  v9 = 256;
  if ( !dword_5EC3D8 )
    v3 = byte_5EA438;
  StringCopyWithBufferRealloc(v3);
  v4 = (char *)dword_5EC420;
  if ( !dword_5EC420 )
    v4 = byte_5EA438;
  sub_5665B0(v4);
  sub_5665B0(aCommon);
  sub_5665B0(aLogomapMas);
  v5 = v8;
  if ( !v8 )
    v5 = byte_5EA438;
  if ( !sub_53CBC0(&v7, v5) )
  {
    if ( a2 )
      CloudSceneObjectRandomSelector((_BYTE *)this, v7);
    sub_4FC400(aWcclouds, (const char *)(this + 80));
    sub_4FC400(aWccloudr, (const char *)(this + 132));
    PhysicsObjectLinkedListRemoval(v7);
  }
  result = v8;
  if ( v8 )
    return (char *)FreeWrapper_7bcf(v8);
  return result;
}

