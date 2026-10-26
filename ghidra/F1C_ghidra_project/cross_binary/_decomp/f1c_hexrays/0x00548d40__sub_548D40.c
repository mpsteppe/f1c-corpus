// f1c  0x00548d40  size=143
int __thiscall sub_548D40(_DWORD *this, int a2, int a3)
{
  int v4; // esi
  _DWORD *v5; // eax
  int *v6; // eax
  int i; // eax
  _DWORD *v8; // eax

  v4 = this[92];
  if ( v4 )
  {
    for ( i = *(_DWORD *)(v4 + 24); i; i = *(_DWORD *)(i + 24) )
      v4 = i;
    v8 = (_DWORD *)sub_587C03(28);
    if ( v8 )
      v6 = sub_548AA0(v8);
    else
      v6 = 0;
    *(_DWORD *)(v4 + 24) = v6;
  }
  else
  {
    v5 = (_DWORD *)sub_587C03(28);
    if ( v5 )
    {
      v6 = sub_548AA0(v5);
      this[92] = v6;
    }
    else
    {
      v6 = 0;
      this[92] = 0;
    }
  }
  if ( sub_548AD0(v6, a2, a3) )
    return -1;
  ++this[91];
  return 0;
}
