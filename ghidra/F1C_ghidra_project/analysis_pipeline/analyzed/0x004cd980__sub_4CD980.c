// Address: 0x004cd980
// Size: 330 bytes
// Name: sub_4CD980
// Type: int __thiscall(int this)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_4CD980(int this)
{
  double v2; // st7
  int result; // eax
  float *v4; // esi
  int v5; // ebp
  int v6; // ebx
  int v7; // [esp+4h] [ebp-18h]
  float v8; // [esp+8h] [ebp-14h]
  float v9; // [esp+Ch] [ebp-10h]
  float v10; // [esp+10h] [ebp-Ch]
  float v11; // [esp+10h] [ebp-Ch]

  if ( dword_8AB6E4 == 2 )
    v2 = sub_4B9CE0(&unk_8AB6EC);
  else
    v2 = dbl_8AFEA0;
  result = *(_DWORD *)(this + 100);
  v9 = v2;
  v7 = 0;
  if ( result > 0 )
  {
    do
    {
      v4 = *(float **)(*(_DWORD *)(this + 104) + 4 * v7);
      v5 = 0;
      v8 = (v9 - v4[2]) * *(float *)(this + 64);
      if ( v8 < (double)v4[25] )
      {
        v10 = (v4[25] - v8) * 254.0;
        v5 = ((int)v10 << 24) + 0xFFFFFF;
      }
      v6 = 0;
      if ( v8 < (double)v4[24] )
      {
        v11 = (v4[24] - v8) * 254.0;
        v6 = ((int)v11 << 24) + 0xFFFFFF;
      }
      if ( v9 <= (double)v4[3] && v9 >= (double)v4[2] && (v5 || v6) )
      {
        sub_558DC0(*(_DWORD *)v4, 0, v5);
        sub_558DC0(*(_DWORD *)v4, 1, v6);
        sub_558DC0(*(_DWORD *)v4, 2, v6);
        sub_558DC0(*(_DWORD *)v4, 3, v5);
      }
      else
      {
        sub_4CB5A0(v4);
        --v7;
      }
      result = ++v7;
    }
    while ( v7 < *(_DWORD *)(this + 100) );
  }
  return result;
}
