double __thiscall sub_42B090(int this, unsigned int a2, int a3)
{
  double result; // st7
  int v4; // edi
  int v6; // eax
  double v7; // st7
  int v8; // [esp-4h] [ebp-Ch]
  float v9; // [esp+10h] [ebp+8h]
  float v10; // [esp+10h] [ebp+8h]
  float v11; // [esp+10h] [ebp+8h]

  result = 0.0;
  v4 = a3;
  if ( !a3 )
    v4 = *(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432);
  switch ( a2 )
  {
    case 8u:
      v8 = 1;
LABEL_5:
      result = sub_529A00(v8);
      goto LABEL_38;
    case 7u:
      result = sub_529A00(0);
      goto LABEL_38;
    case 6u:
      result = sub_529A00(0) - 3.5;
      goto LABEL_38;
    case 9u:
      result = sub_529A00(1) + 3.5;
      goto LABEL_38;
    case 0xBu:
      v6 = *(_DWORD *)(this + 28);
      v8 = 2;
      if ( v6 == 1 )
      {
        v9 = sub_529A00(2) * (1.0 - *(float *)(this + 24));
        result = sub_529A00(0) * *(float *)(this + 24) + v9;
      }
      else
      {
        if ( v6 != 2 )
          goto LABEL_5;
        v10 = sub_529A00(2) * (1.0 - *(float *)(this + 24));
        result = sub_529A00(1) * *(float *)(this + 24) + v10;
      }
      goto LABEL_38;
    case 0xAu:
      result = sub_529A00(2) - 3.5;
      goto LABEL_38;
    case 5u:
      result = sub_529A00(0) - 6.5;
      goto LABEL_38;
    case 0xCu:
      result = sub_529A00(0) + 2.25;
      goto LABEL_38;
    case 0xFu:
      result = sub_529A00(3);
      goto LABEL_38;
    case 0x11u:
      result = sub_529A00(4);
      goto LABEL_38;
    case 0x10u:
      v11 = sub_529A00(4);
      v7 = sub_529A00(3) + v11;
LABEL_37:
      result = v7 * 0.5;
      goto LABEL_38;
    case 0xDu:
      result = sub_42B090(*(_DWORD *)(this + 24192), v4) + *(float *)(this + 24184);
      goto LABEL_38;
    case 0xEu:
      result = sub_42B090(*(_DWORD *)(this + 24196), v4) + *(float *)(this + 24188);
      goto LABEL_38;
  }
  if ( a2 <= 1 )
  {
    if ( fabs(*(float *)(this + 23728) - *(float *)(*(_DWORD *)(this + 23432) + 128)) + 1.0 <= fabs(
                                                                                                 *(float *)(this + 23728)
                                                                                               - -*(float *)(*(_DWORD *)(this + 23432) + 124)) )
      v7 = *(float *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 160) - 1.5 + *(float *)(v4 + 128);
    else
      v7 = 1.5 - (*(float *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 156) + *(float *)(v4 + 124));
    goto LABEL_37;
  }
LABEL_38:
  if ( dword_75CBB0 != 5 )
    return result
         + (sin(*(float *)(this + 23852) / *(float *)(this + 24048)) * *(float *)(this + 24052)
          - *(float *)(this + 24052))
         * *(float *)(this + 12);
  return result;
}
