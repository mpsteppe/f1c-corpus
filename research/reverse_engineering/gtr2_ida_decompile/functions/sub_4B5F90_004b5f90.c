int __thiscall sub_4B5F90(_DWORD *this, int a2)
{
  int *v2; // eax
  int v3; // esi
  int v4; // esi
  _DWORD *v5; // edx
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  bool v11; // cc
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax

  v2 = (int *)this[210];
  v3 = *v2;
  if ( a2 == 1 )
    v4 = this[214] + v3;
  else
    v4 = v3 - this[215];
  *v2 = v4;
  v5 = (_DWORD *)this[210];
  v6 = this[213];
  if ( *v5 < v6 || (v6 = this[212], *v5 > v6) )
    *v5 = v6;
  switch ( *(_DWORD *)this[210] )
  {
    case 0:
      v7 = dword_B71A0C;
      dword_B71A04 = 0;
      if ( dword_B71A0C > 0 || (v7 = dword_B71A10, dword_B71A10 < 0) )
        dword_B71A04 = v7;
      v8 = dword_B719E8;
      dword_B719E0 = 0;
      if ( dword_B719E8 > 0 || (v8 = dword_B719EC, dword_B719EC < 0) )
        dword_B719E0 = v8;
      v9 = dword_B719C4;
      dword_B719BC = 0;
      if ( dword_B719C4 > 0 || (v9 = dword_B719C8, dword_B719C8 < 0) )
        dword_B719BC = v9;
      v10 = dword_B71A30;
      dword_B71A28 = 0;
      if ( dword_B71A30 > 0 )
        goto LABEL_31;
      v10 = dword_B71A34;
      v11 = dword_B71A34 < 0;
      goto LABEL_30;
    case 1:
    case 2:
    case 3:
      v12 = dword_B71A0C;
      dword_B71A04 = 1;
      if ( dword_B71A0C > 1 || (v12 = dword_B71A10, dword_B71A10 < 1) )
        dword_B71A04 = v12;
      v13 = dword_B719E8;
      dword_B719E0 = 1;
      if ( dword_B719E8 > 1 || (v13 = dword_B719EC, dword_B719EC < 1) )
        dword_B719E0 = v13;
      v14 = dword_B719C4;
      dword_B719BC = 1;
      if ( dword_B719C4 > 1 || (v14 = dword_B719C8, dword_B719C8 < 1) )
        dword_B719BC = v14;
      v10 = dword_B71A30;
      dword_B71A28 = 1;
      if ( dword_B71A30 > 1 )
        goto LABEL_31;
      v10 = dword_B71A34;
      v11 = dword_B71A34 < 1;
LABEL_30:
      if ( v11 )
LABEL_31:
        dword_B71A28 = v10;
      break;
    default:
      break;
  }
  v15 = dword_B71D88;
  dword_B71D80 = 0;
  if ( dword_B71D88 > 0 || (v15 = dword_B71D8C, dword_B71D8C < 0) )
    dword_B71D80 = v15;
  return (*(int (__thiscall **)(_DWORD *))(*this + 184))(this);
}
