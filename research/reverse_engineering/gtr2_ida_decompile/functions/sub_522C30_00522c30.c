int __thiscall sub_522C30(int *this, int a2, char a3)
{
  double v3; // st7
  int v4; // ecx
  int v6; // ecx
  int v7; // ecx
  double v8; // st7
  int v9; // ecx
  int v10; // ecx
  int v11; // [esp+0h] [ebp-8h]
  int v12; // [esp+0h] [ebp-8h]
  int v13; // [esp+0h] [ebp-8h]
  int v14; // [esp+0h] [ebp-8h]
  int v15; // [esp+Ch] [ebp+4h]

  switch ( a2 )
  {
    case 0:
      v3 = dbl_FB1D08;
      goto LABEL_4;
    case 1:
      v3 = dbl_FB1D08 * 3.0;
LABEL_4:
      *(float *)&v15 = *((float *)this + 723213) - v3;
      if ( !a3 && *(float *)&v15 < (double)*((float *)this + 723242) )
        v15 = this[723242];
      sub_522980(this, v15);
      *(_DWORD *)(v4 + 2892972) = 4;
      goto LABEL_8;
    case 2:
      sub_522980(this, this[723213]);
      *(_DWORD *)(v6 + 2892972) = 5;
      return sub_540130(&unk_BE1D30);
    case 3:
      *(float *)&v12 = dbl_FB1D08 + *((float *)this + 723213);
      sub_522980(this, v12);
      *(_DWORD *)(v7 + 2892972) = 6;
      goto LABEL_8;
    case 4:
      v8 = dbl_FB1D08 * 0.33333334;
      goto LABEL_13;
    case 5:
      v8 = dbl_FB1D08 * 0.1;
LABEL_13:
      *(float *)&v13 = v8 + *((float *)this + 723213);
      sub_522980(this, v13);
      *(_DWORD *)(v9 + 2892972) = 6;
      v11 = 1056964608;
      goto LABEL_8;
    case 6:
      *(float *)&v14 = dbl_FB1D08 * 4.0 + *((float *)this + 723213);
      sub_522980(this, v14);
      *(_DWORD *)(v10 + 2892972) = 7;
      v11 = 0x40000000;
      goto LABEL_8;
    default:
      if ( a2 == 2 )
        return sub_540130(&unk_BE1D30);
LABEL_8:
      sub_540140(&unk_BE1D30);
      return sub_540190(v11);
  }
}
