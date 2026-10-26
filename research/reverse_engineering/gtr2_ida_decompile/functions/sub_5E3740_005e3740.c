int __thiscall sub_5E3740(int *this, int a2, int a3)
{
  int v3; // ebx
  int i; // edi
  int v5; // eax
  int v6; // eax
  int v8; // eax
  int v9; // eax
  int v10; // [esp+10h] [ebp-8h]

  v3 = 0;
  v10 = 0;
  if ( a2 )
  {
    v8 = sub_5E8220(99);
    v9 = *(_DWORD *)(sub_5E80D0(a3 + v8) + 4);
    if ( v9 > 1 )
      return v9;
    return v10;
  }
  if ( this[90] <= 0 )
    return v10;
  for ( i = this[91] + 4; ; i += 108 )
  {
    v5 = sub_5E8220(99);
    v6 = sub_5E80D0(a3 + v5);
    if ( *(int *)(v6 + 4) > 1 )
      break;
    if ( ++v3 >= this[90] )
      return 0;
  }
  return *(_DWORD *)(v6 + 4);
}
