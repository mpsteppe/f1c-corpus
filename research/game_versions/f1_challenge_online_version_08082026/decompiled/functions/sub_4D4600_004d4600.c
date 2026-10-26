_DWORD *__thiscall sub_4D4600(int this)
{
  _DWORD *v2; // ecx
  void *v3; // edi
  void *v4; // eax
  int i; // edi
  int v6; // eax
  int v7; // ecx
  void *v8; // ebp
  int v9; // edi
  int v10; // ecx
  void *v11; // eax
  _DWORD *result; // eax
  int v13; // ecx
  int v14; // [esp+Ch] [ebp-4h]

  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_3, 2855) )
    sub_4D7AA0(&unk_8AD25C, aEnteredSteward_2);
  v2 = *(_DWORD **)(this + 168);
  if ( v2 )
  {
    sub_4482D0(v2);
    v3 = *(void **)(this + 168);
    if ( v3 )
    {
      sub_4482D0(*(_DWORD **)(this + 168));
      sub_587BCF(v3);
    }
    *(_DWORD *)(this + 168) = 0;
  }
  sub_4D2E20((int **)this);
  sub_4D24D0();
  sub_40DA30((char *)this);
  v4 = *(void **)(this + 272);
  *(_DWORD *)(this + 268) = 0;
  if ( v4 )
  {
    sub_587BCF(v4);
    *(_DWORD *)(this + 272) = 0;
  }
  if ( *(_DWORD *)(this + 276) )
  {
    sub_587BCF(*(LPVOID *)(this + 276));
    *(_DWORD *)(this + 276) = 0;
  }
  if ( dword_7D0410 != 4 )
    sub_4C2A80(dword_7D2DB0);
  for ( i = 0; i < dword_5C329C; ++i )
    sub_4BB950(dword_7C54F0[i] + 16436);
  if ( *(_DWORD *)(this + 272) )
  {
    sub_587BCF(*(LPVOID *)(this + 272));
    *(_DWORD *)(this + 272) = 0;
  }
  v6 = *(_DWORD *)(this + 428);
  *(_DWORD *)(this + 424) = 0;
  if ( v6 )
  {
    v7 = *(_DWORD *)(v6 - 4);
    v8 = (void *)(v6 - 4);
    v9 = v6 + 8 * v7;
    v10 = v7 - 1;
    if ( v10 >= 0 )
    {
      v14 = v10 + 1;
      do
      {
        v11 = *(void **)(v9 - 8);
        v9 -= 8;
        if ( v11 )
          sub_587BCF(v11);
        --v14;
      }
      while ( v14 );
    }
    sub_587BCF(v8);
    *(_DWORD *)(this + 428) = 0;
  }
  result = (_DWORD *)(this + 640);
  v13 = 52;
  do
  {
    *(result - 52) = 0;
    *result++ = 0;
    --v13;
  }
  while ( v13 );
  return result;
}
