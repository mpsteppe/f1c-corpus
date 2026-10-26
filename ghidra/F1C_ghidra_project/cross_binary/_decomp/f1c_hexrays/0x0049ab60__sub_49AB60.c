// f1c  0x0049ab60  size=191
__int16 __thiscall sub_49AB60(__int16 *this, int a2, int a3, int a4, int a5)
{
  bool v6; // cc
  __int16 *v7; // ecx
  int v8; // eax
  __int16 v9; // bx
  __int16 v10; // di
  __int16 v11; // dx
  __int16 v12; // si

  v6 = this[20] <= 0;
  v7 = this + 18;
  if ( v6 || v7[3] <= 0 )
    return sub_4916E0(v7, a4, a2, a5 - a4, a3 - a2);
  v8 = this[19];
  v9 = v8;
  if ( v8 >= a2 )
    v9 = a2;
  v10 = a3;
  if ( v7[3] + v7[1] - 1 > a3 )
    v10 = v7[1] + v7[3] - 1;
  v11 = a4;
  if ( *v7 < a4 )
    v11 = *v7;
  v12 = a5;
  if ( v7[2] + *v7 - 1 > a5 )
    v12 = *v7 + v7[2] - 1;
  return sub_4916E0(v7, v11, v9, v12 - v11, v10 - v9);
}
