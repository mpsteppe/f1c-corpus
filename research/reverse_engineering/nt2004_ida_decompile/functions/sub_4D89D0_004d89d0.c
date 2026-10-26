int __thiscall sub_4D89D0(int this, int a2, char a3)
{
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  float v9; // [esp+0h] [ebp-Ch]
  float v10; // [esp+0h] [ebp-Ch]
  float v11; // [esp+0h] [ebp-Ch]
  float v12; // [esp+0h] [ebp-Ch]
  int v13; // [esp+8h] [ebp-4h]
  float v14; // [esp+10h] [ebp+4h]

  v13 = 1065353216;
  switch ( a2 )
  {
    case 0:
      v14 = sub_4D83C0((float *)this) - dbl_7DA9C0;
      if ( !a3 && v14 < (double)*(float *)(this + 2156) )
        v14 = *(float *)(this + 2156);
      sub_4D82E0(this, v14);
      *(_DWORD *)(this + 2164) = 4;
      goto LABEL_6;
    case 1:
      v9 = sub_4D83C0((float *)this);
      sub_4D82E0(v5, v9);
      *(_DWORD *)(this + 2164) = 5;
      return sub_4F01A0(&byte_7D6B78);
    case 2:
      v10 = sub_4D83C0((float *)this) + dbl_7DA9C0;
      sub_4D82E0(v6, v10);
      *(_DWORD *)(this + 2164) = 6;
      goto LABEL_6;
    case 3:
      v11 = sub_4D83C0((float *)this) + dbl_7DA9C0 * 0.083333336;
      sub_4D82E0(v7, v11);
      *(_DWORD *)(this + 2164) = 6;
      v13 = 1056964608;
      goto LABEL_6;
    case 4:
      v12 = sub_4D83C0((float *)this) + dbl_7DA9C0 * 3.3399999;
      sub_4D82E0(v8, v12);
      *(_DWORD *)(this + 2164) = 7;
      v13 = 1070973583;
      goto LABEL_6;
    default:
      if ( a2 == 1 )
        return sub_4F01A0(&byte_7D6B78);
LABEL_6:
      sub_4F01B0(&byte_7D6B78);
      return sub_4F0200(v13);
  }
}
