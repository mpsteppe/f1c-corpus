int __usercall sub_5291F0@<eax>(int a1@<ecx>, int a2@<edi>)
{
  int v3; // ecx
  int i; // ebx
  char *v5; // edi
  char v6; // al
  char v7; // al
  int result; // eax
  int v9; // [esp+4h] [ebp-1Ch]
  int v10; // [esp+10h] [ebp-10h]
  float v11; // [esp+10h] [ebp-10h]
  int v12; // [esp+10h] [ebp-10h]
  int v13[2]; // [esp+18h] [ebp-8h] BYREF

  *(_BYTE *)(a1 + 2892960) = 1;
  sub_40E040((int)&flt_757718, 0.0);
  *(_BYTE *)(a1 + 2892960) = 1;
  *(float *)&v10 = dbl_FB1D18;
  v13[1] = 2;
  sub_522980((void *)a1, v10);
  sub_5283B0(v3, a2, v13);
  *(_DWORD *)(a1 + 2892916) = *(_DWORD *)(a1 + 2892920);
  *(_BYTE *)(a1 + 2892961) = 0;
  sub_561B20(-1);
  for ( i = sub_42DA10(&unk_920488); dword_920480 < 105; i = sub_42DA60(&unk_920488) )
  {
    v5 = (char *)&unk_9204A0 + 22616 * i;
    sub_53E6A0(v5, *(_DWORD *)(a1 + 4 * i + 1916));
    sub_5725E0(v5 + 2704);
    v6 = *(_BYTE *)(a1 + i + 2336);
    if ( v5[5754] != v6 )
    {
      v5[5754] = v6;
      sub_56AE80(*((_DWORD *)v5 + 1436), 1);
    }
    v11 = dbl_FB1D18;
    sub_56BD70(v5 + 2704, LODWORD(v11));
    sub_53F190((char *)&unk_9204A0 + 22616 * i, *(unsigned __int8 *)(a1 + i + 2441), v12);
    v7 = *(_BYTE *)(a1 + i + 2546);
    if ( v5[5753] != v7 )
    {
      v9 = *((_DWORD *)v5 + 1436);
      v5[5753] = v7;
      sub_56AE80(v9, 1);
    }
    sub_4FD030((int)(v5 + 14824), 27504 * i + a1 + 2656);
  }
  sub_417230(&dword_91BF88);
  sub_540190(1065353216);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)(a1 + 1780) + 52))(a1 + 1780, *(_DWORD *)(a1 + 2892860));
  result = 1;
  *(_DWORD *)(a1 + 2892844) = 0;
  *(_DWORD *)(a1 + 2892848) = 0;
  *(_DWORD *)(a1 + 2892860) = -1;
  return result;
}
