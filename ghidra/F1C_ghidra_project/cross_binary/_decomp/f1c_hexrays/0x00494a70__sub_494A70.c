// f1c  0x00494a70  size=375
int __stdcall sub_494A70(
        int a1,
        float a2,
        float a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14)
{
  float v14; // ecx
  int result; // eax
  float v16; // ebx
  float v17; // [esp+4h] [ebp+4h]
  float v18; // [esp+8h] [ebp+8h]
  float v19; // [esp+Ch] [ebp+Ch]
  float v20; // [esp+10h] [ebp+10h]
  float v21; // [esp+10h] [ebp+10h]
  float v22; // [esp+14h] [ebp+14h]
  float v23; // [esp+1Ch] [ebp+1Ch]
  float v24; // [esp+20h] [ebp+20h]

  v14 = *(float *)&a4;
  if ( a4 >= 0 )
  {
    if ( a4 <= 256 )
      goto LABEL_6;
    LODWORD(v14) = 256;
  }
  else
  {
    v14 = 0.0;
  }
  *(float *)&a4 = v14;
LABEL_6:
  result = a5;
  if ( a5 >= 0 )
  {
    if ( a5 <= 256 )
      goto LABEL_11;
    result = 256;
  }
  else
  {
    *(float *)&result = 0.0;
  }
  a5 = result;
LABEL_11:
  if ( SLODWORD(v14) > 0 && result > 0 )
  {
    sub_543250(LODWORD(a2), LODWORD(a3), dword_7CDE08, 0, 0, LODWORD(v14), result, 0, 0);
    v18 = (float)a7;
    v19 = (float)a8;
    v23 = (float)a9;
    v17 = (float)a10;
    v24 = (double)a4 * 0.00390625;
    v20 = (double)a5 * 0.00390625;
    sub_553650(0, v18, v19, 1.0, 0.0, 0.0, a11);
    v16 = v20;
    v22 = v17 + v19;
    sub_553650(1, v18, v22, 1.0, 0.0, v20, a12);
    v21 = v23 + v18;
    sub_553650(2, v21, v22, 1.0, v24, v16, a13);
    sub_553650(3, v21, v19, 1.0, v24, 0.0, a14);
    sub_4F9F00(&unk_8AFE18);
    sub_553700(a6);
    *(float *)&result = COERCE_FLOAT(sub_4F9F30(&unk_8AFE18));
  }
  return result;
}
