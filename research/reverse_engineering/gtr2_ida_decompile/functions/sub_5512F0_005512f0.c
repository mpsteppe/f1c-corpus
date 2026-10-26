char __thiscall sub_5512F0(_BYTE *this, int a2, int a3, char a4)
{
  int v5; // eax
  int v6; // ecx
  int v7; // ebp
  float *v8; // ecx

  if ( a4 )
    goto LABEL_6;
  v5 = (unsigned __int8)this[a2 + 472];
  if ( v5 >= dword_757C10
    || (v6 = a2 + 5654 * a3, v7 = dword_92508C[v6], v8 = (float *)(4 * v6 + 9588876), v7 != -1082130432)
    && *v8 <= (double)*(float *)&dword_92508C[5654 * v5 + a2] )
  {
    sub_414510();
LABEL_6:
    this[a2 + 472] = a3;
    return 1;
  }
  return 0;
}
