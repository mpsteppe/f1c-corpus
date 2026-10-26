// f1c  0x0049eb40  size=252
int __thiscall sub_49EB40(int this, int a2, int a3, int a4, int a5, float a6)
{
  int result; // eax
  float v9; // esi
  float v10; // ebp
  float v11; // [esp+Ch] [ebp+4h]
  float v12; // [esp+Ch] [ebp+4h]
  float v13; // [esp+Ch] [ebp+4h]
  float v14; // [esp+1Ch] [ebp+14h]

  result = *(_DWORD *)(this + 12);
  if ( result )
  {
    sub_49ECA0(this);
    result = sub_553980(this + 4, LODWORD(a6), *(_DWORD *)(this + 12), 32, 192);
    if ( !result )
    {
      v14 = (float)a2;
      v11 = (float)a3;
      *(float *)(this + 60) = *(float *)&a2;
      *(_DWORD *)(this + 68) = a4;
      *(_DWORD *)(this + 64) = a3;
      *(_DWORD *)(this + 72) = a5;
      v9 = v11;
      sub_553650(0, v14, v11, 1.0, 0.0, 0.0, -1);
      v12 = (double)a5 + v11;
      v10 = v12;
      sub_553650(1, v14, v12, 1.0, 0.0, 1.0, -1);
      v13 = (double)a4 + v14;
      sub_553650(2, v13, v10, 1.0, 1.0, 1.0, -1);
      return sub_553650(3, v13, v9, 1.0, 1.0, 0.0, -1);
    }
  }
  return result;
}
