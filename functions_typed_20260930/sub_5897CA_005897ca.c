_BYTE *__cdecl sub_5897CA(_BYTE *a1, char *a2)
{
  char v3; // dl
  _BYTE *v4; // edx
  _BYTE *v5; // ebx
  _BYTE v7[32]; // [esp+Ch] [ebp-20h] BYREF
  int v8; // [esp+38h] [ebp+Ch]

  v8 = TLSValueRetrievalWithInit();
  memset(v7, 0, sizeof(v7));
  do
  {
    v3 = *a2;
    v7[(unsigned __int8)*a2 >> 3] |= 1 << (*a2 & 7);
    ++a2;
  }
  while ( v3 );
  v4 = a1;
  if ( !a1 )
    v4 = *(_BYTE **)(v8 + 24);
  while ( ((unsigned __int8)(1 << (*v4 & 7)) & v7[(unsigned __int8)*v4 >> 3]) != 0 && *v4 )
    ++v4;
  v5 = v4;
  while ( *v4 )
  {
    if ( ((unsigned __int8)(1 << (*v4 & 7)) & v7[(unsigned __int8)*v4 >> 3]) != 0 )
    {
      *v4++ = 0;
      break;
    }
    ++v4;
  }
  *(_DWORD *)(v8 + 24) = v4;
  return v4 != v5 ? v5 : 0;
}

