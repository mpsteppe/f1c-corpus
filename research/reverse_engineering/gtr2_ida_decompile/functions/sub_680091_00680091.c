_DWORD *__thiscall sub_680091(_DWORD *this)
{
  _DWORD *v2; // eax
  int v3; // eax
  _DWORD *v5; // [esp+4h] [ebp-4h]

  v2 = (_DWORD *)sub_65B229(64);
  if ( v2 )
    v5 = sub_67F6CC(v2);
  else
    v5 = 0;
  if ( v5
    && ((v5[4] = this[4],
         v5[5] = this[5],
         v5[6] = this[6],
         v5[7] = this[7],
         qmemcpy(v5 + 8, this + 8, 0x20u),
         this[4] != 4)
     || !this[6]
     || (v3 = sub_67ECC3(this[6]), (this[6] = v3) != 0)) )
  {
    return v5;
  }
  else
  {
    return 0;
  }
}
