int __stdcall sub_5008E4(int a1, int a2, int a3, int a4, int a5, int *a6, int a7, int a8, int a9)
{
  int v9; // eax
  int v10; // esi
  int v12[21]; // [esp+Ch] [ebp-64h] BYREF
  int v13; // [esp+60h] [ebp-10h] BYREF
  int v14; // [esp+64h] [ebp-Ch]
  int v15; // [esp+68h] [ebp-8h]
  int v16; // [esp+6Ch] [ebp-4h]

  sub_500F3C(v12);
  if ( !a1 || !a4 || !a5 )
    goto LABEL_13;
  v9 = sub_502A15(a4, a5, a9, 1);
  if ( v9 >= 0 )
  {
    if ( a6 )
    {
      v13 = *a6;
      v14 = a6[1];
      v15 = a6[2];
      v16 = a6[3];
      if ( v13 < 0 || v15 > v12[3] || v13 > v15 || v14 < 0 || v16 > v12[4] || v14 > v16 )
      {
LABEL_13:
        v10 = -2005530516;
        goto LABEL_14;
      }
    }
    else
    {
      v13 = v12[6];
      v14 = v12[7];
      v15 = v12[8];
      v16 = v12[9];
    }
    v9 = sub_50070D(a1, a2, a3, v12[1], v12[0], v12[12], v12[2], &v13, a7, a8);
    if ( v9 >= 0 )
    {
      v10 = 0;
      goto LABEL_14;
    }
  }
  v10 = v9;
LABEL_14:
  sub_500F55(v12);
  return v10;
}
