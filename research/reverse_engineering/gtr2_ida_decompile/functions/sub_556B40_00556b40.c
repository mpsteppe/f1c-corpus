void __usercall sub_556B40(int a1@<ecx>, int a2@<edi>)
{
  int i; // edi
  char v4; // al
  _DWORD *v5; // ecx
  bool v6; // bl
  bool v7; // al
  int v8; // eax
  char *v9; // eax
  char *v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // edi
  char *v13; // eax
  int v14; // [esp+4h] [ebp-14h]
  int v15; // [esp+8h] [ebp-10h]
  int v16; // [esp+14h] [ebp-4h]

  if ( sub_473630(&dword_B6CBA8)
    && dword_B6CBC4
    && ((double)dword_B6CBC4 < dbl_FB1D18 - (double)*(int *)(a1 + 208) || !*(_DWORD *)(a1 + 208)) )
  {
    *(_DWORD *)(a1 + 208) = (unsigned __int64)dbl_FB1D18;
    sub_553180(a2, (const CHAR *)1);
    for ( i = 0; i < 104; ++i )
      sub_552190(i, 1, 0);
  }
  if ( *(int *)dword_B640C8 >= 0 )
  {
    if ( *(int *)dword_B640C8 <= 5 )
    {
      if ( (*(float *)(a1 + 224) + *(float *)(a1 + 220)) * 0.5 <= dbl_FB1D18 )
        *(_BYTE *)(a1 + 252) = 1;
      sub_551400(a1);
      if ( *(_DWORD *)dword_B72314 != 1 || !dword_B71F00 )
        sub_556440((float *)a1);
    }
    else if ( *(_DWORD *)dword_B640C8 == 6 )
    {
      if ( (dword_B698E8 & 1) != 0 && (byte_B69A25 & 2) != 0 && !byte_B6F118 )
        *(_BYTE *)(a1 + 244) = 1;
      sub_52B550((int)&byte_9034D0);
      switch ( dword_B64134 )
      {
        case 0:
        case 1:
          if ( (unsigned __int8)sub_4735A0() )
          {
            if ( dword_757C10 == *(_DWORD *)(a1 + 248) )
              *(_BYTE *)(a1 + 244) = 1;
          }
          if ( *(_BYTE *)(a1 + 244) )
          {
            sub_45EAE0(57);
            sub_472920((const char **)&dword_B6CB98, "00:01", 0);
            if ( !dword_B70174 )
              goto LABEL_22;
            *(float *)&v15 = dbl_FB1D18 + 300.0;
            sub_551B20(2, v15);
          }
          break;
        case 2:
          v6 = *(_BYTE *)(a1 + 244) && *(float *)(a1 + 152) > 1.5;
          v7 = !(unsigned __int8)sub_415220() && *(float *)(a1 + 224) - 300.0 + 1.5 < dbl_FB1D18;
          if ( v6 || v7 )
          {
            sub_45EAE0(57);
            sub_415F50(a1);
LABEL_22:
            v4 = sub_42FE50(&dword_B640C0);
            v5 = (_DWORD *)a1;
            if ( !v4 )
              goto LABEL_53;
            sub_551B20(3, 2139095039);
          }
          break;
        case 3:
          if ( (unsigned __int8)sub_4735A0() && byte_B73540 )
            *(_BYTE *)(a1 + 244) = 1;
          v8 = *(_DWORD *)(a1 + 240);
          if ( v8 == 2139095039 || v8 == -8388609 )
          {
            if ( sub_42FE50(&dword_B640C0) )
            {
              if ( *(_DWORD *)(a1 + 224) == 2139095039 && sub_5503D0((_BYTE *)a1) )
              {
                *(float *)&v16 = dbl_FB1D18 + 1.0;
                *(float *)(a1 + 224) = *(float *)&v16;
                sub_551B20(3, v16);
              }
            }
            else if ( sub_551A30((float *)a1) )
            {
              sub_551BC0((_DWORD *)a1);
            }
          }
          sub_551970(a1);
          if ( *(_DWORD *)(a1 + 240) == 2139095039 && *(_DWORD *)(a1 + 224) == 2139095039 )
          {
            if ( *(_BYTE *)(a1 + 244) )
            {
              v9 = sub_41D840(&byte_91CC38, "Press SPACE To Skip Formation Lap");
              sub_472920((const char **)&dword_B6CB98, v9, 0);
              v10 = sub_41D840(&byte_91CC38, "Beginning Formation Lap");
              sub_472920((const char **)&dword_B6CB98, v10, 0);
              *(float *)(a1 + 240) = dbl_FB1D18 + 3.0;
              v11 = (_DWORD *)sub_416730(&dword_82F4A0);
              *(float *)&v14 = dbl_FB1D18;
              v12 = v11;
              sub_51B2A0(v11, 4, 20, 4, 255, v14, 3);
              v12[2] = *(_DWORD *)(a1 + 240);
            }
            else
            {
              v13 = sub_41D840(&byte_91CC38, "Press SPACE To Skip Formation Lap");
              sub_4730C0((int **)&dword_B6CB98, v13, 3, (int)&byte_1020304, 1084227584);
            }
          }
          break;
        case 4:
          if ( *(_DWORD *)(a1 + 284) == 2139095039 )
          {
            v5 = (_DWORD *)a1;
LABEL_53:
            sub_551BC0(v5);
          }
          break;
        case 5:
        case 6:
        case 7:
        case 8:
          if ( (*(float *)(a1 + 224) + *(float *)(a1 + 220)) * 0.5 <= dbl_FB1D18 )
            *(_BYTE *)(a1 + 252) = 1;
          if ( !sub_473550() && dword_BE1204 != 2 && dword_B6E4DC == 1 )
          {
            sub_4EA8F0();
            dword_B6E4DC = 7;
          }
          sub_551400(a1);
          sub_556440((float *)a1);
          break;
        default:
          return;
      }
    }
  }
}
