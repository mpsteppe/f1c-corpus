// f1c  0x0049acc0  size=138
int __thiscall sub_49ACC0(_DWORD *this, int a2, int a3)
{
  int v5; // eax
  __int16 v6; // cx
  bool v7; // cc
  int v8; // eax
  __int16 v9; // bx
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int **v13; // eax
  int v14; // edx
  int v15; // ecx
  int result; // eax
  int v17; // [esp-8h] [ebp-18h]
  int v18; // [esp-4h] [ebp-14h]
  __int16 v19; // [esp+18h] [ebp+8h]

  v5 = this[1];
  v6 = v5 + a3;
  v7 = v5 < v5 + a3;
  v19 = v5;
  if ( !v7 )
    v19 = v6;
  v8 = this[2];
  v9 = v8;
  if ( v8 <= v8 + a3 )
    v9 = v8 + a3;
  v10 = this[3];
  v11 = v10;
  if ( v10 >= v10 + a2 )
    v11 = v10 + a2;
  v12 = this[4];
  if ( v12 <= v12 + a2 )
    v12 += a2;
  if ( this[16] )
  {
    v18 = v12;
    v17 = v11;
    v13 = (int **)sub_490920();
    sub_4918D0(v13, v19, v9, v17, v18);
  }
  v14 = a3 + this[2];
  v15 = a2 + this[3];
  result = a2 + this[4];
  this[1] += a3;
  this[2] = v14;
  this[3] = v15;
  this[4] = result;
  return result;
}
