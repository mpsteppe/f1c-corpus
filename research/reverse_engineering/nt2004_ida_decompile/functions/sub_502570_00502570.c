int __thiscall sub_502570(float *this, float a2)
{
  int v3; // ebx
  int *v4; // edi
  double v5; // st7
  float v6; // esi
  float v7; // ebp
  float v9; // [esp+Ch] [ebp-Ch]
  float v10; // [esp+Ch] [ebp-Ch]
  float v11; // [esp+10h] [ebp-8h]
  float v12; // [esp+10h] [ebp-8h]
  float v13; // [esp+14h] [ebp-4h]
  float v14; // [esp+14h] [ebp-4h]
  float v15; // [esp+1Ch] [ebp+4h]
  float v16; // [esp+1Ch] [ebp+4h]
  float v17; // [esp+1Ch] [ebp+4h]
  float v18; // [esp+1Ch] [ebp+4h]

  v3 = 1;
  sub_5027D0(LODWORD(a2));
  switch ( LODWORD(a2) )
  {
    case 1:
      v4 = &dword_7D79E0;
      v15 = 25.0;
      v11 = 175.0;
      goto LABEL_8;
    case 2:
      v4 = &dword_7D79E4;
      v15 = 800.0;
      v11 = 1600.0;
      goto LABEL_8;
    case 3:
      v4 = &dword_7D79E8;
      v11 = 150.0;
      goto LABEL_7;
    case 4:
      v4 = &dword_7D79EC;
      v9 = 870.0;
      v15 = 150.0;
      v13 = 410.0;
      v11 = 220.0;
      goto LABEL_9;
    case 5:
      v4 = (int *)&flt_7D79F0;
      v11 = 50.0;
LABEL_7:
      v15 = 0.0;
LABEL_8:
      v9 = 0.0;
      v13 = 1280.0;
LABEL_9:
      if ( !*v4 )
      {
        sub_5A1A60(v4, 2, 0, 32, 64);
        if ( *v4 )
        {
          v10 = v9 * this[22];
          v16 = v15 * this[23];
          v14 = v13 * this[22];
          v5 = v11 * this[23];
          v6 = v16;
          v12 = v5;
          sub_5A16E0(*v4, 0, v10, v16, 1.0, 0.0, 0.0, 0x80000000);
          v17 = v12 + v16;
          v7 = v17;
          sub_5A16E0(*v4, 1, v10, v17, 1.0, 0.0, 1.0, 0x80000000);
          v18 = v14 + v10;
          sub_5A16E0(*v4, 2, v18, v7, 1.0, 1.0, 1.0, 0x80000000);
          sub_5A16E0(*v4, 3, v18, v6, 1.0, 1.0, 0.0, 0x80000000);
          v3 = 0;
        }
      }
      break;
    default:
      return v3;
  }
  return v3;
}
