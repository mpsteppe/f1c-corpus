// f1c  0x004cd980  size=330
int __usercall sub_4CD980@<eax>(int a1@<ecx>, double a2@<st0>)
{
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
    sub_4B9CE0(&dword_8AB6EC);
  else
    a2 = dbl_8AFEA0;
  result = *(_DWORD *)(a1 + 100);
  v9 = a2;
  v7 = 0;
  if ( result > 0 )
  {
    do
    {
      v4 = *(float **)(*(_DWORD *)(a1 + 104) + 4 * v7);
      v5 = 0;
      v8 = (v9 - v4[2]) * *(float *)(a1 + 64);
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
        sub_4CB5A0((_DWORD *)a1, v4);
        --v7;
      }
      result = ++v7;
    }
    while ( v7 < *(_DWORD *)(a1 + 100) );
  }
  return result;
}
