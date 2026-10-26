// positive sp value has been detected, the output may be wrong!
void __userpurge sub_457850(int a1@<edi>, int a2@<esi>, int a3, int a4)
{
  int v4; // ecx
  int v5; // esi
  double v6; // st7
  int v7; // ebp
  const CHAR *v8; // eax
  const CHAR *v9; // eax
  unsigned int v11; // [esp-3C64h] [ebp-3C88h]
  int v12; // [esp-3C60h] [ebp-3C84h] BYREF
  int v13; // [esp-3C5Ch] [ebp-3C80h] BYREF
  int v14; // [esp-1E90h] [ebp-1EB4h] BYREF
  _DWORD v15[1964]; // [esp-1E8Ch] [ebp-1EB0h] BYREF
  int retaddr; // [esp+24h] [ebp+0h]

  sub_631BD0();
  v5 = v4;
  *(_DWORD *)(v4 + 9392) = a4;
  *(double *)(v4 + 6440) = *(float *)(a4 + 16084);
  v12 = sub_615460(512);
  *(double *)(v5 + 128) = dbl_FB1D18;
  *(double *)(v5 + 136) = 1.0 / (double)(400 >> dword_B6FC28);
  v6 = (double)(400 >> dword_B6FC28) * 0.8;
  dbl_911668 = v6 * v6;
  dbl_911670 = v6 + v6;
  sub_435800(a1, a2);
  retaddr = 1;
  ((void (__thiscall *)(int *))sub_5875F0)(&v13);
  v7 = dword_BE1BD8 + 2824 * *(_DWORD *)(a4 + 22472);
  v8 = *(const CHAR **)(v7 + 8);
  if ( !v8 )
    v8 = WindowName;
  sub_5886A0(v8, v15, 0);
  v11 = strlen((const char *)(a4 + 22212));
  if ( v11 )
    sub_5886A0(a4 + 22212, v15, 1);
  sub_440C80();
  sub_44B730(v5, a4 + 22213, (int)&v14, (int)&v12);
  sub_44E970(v5, (int)&v14, (int)&v12);
  sub_44B580(v5);
  v9 = *(const CHAR **)(v7 + 16);
  if ( !v9 )
    v9 = WindowName;
  sub_4576F0(v5, (int)v9, (float *)(v7 + 56));
  *(_BYTE *)(v5 + 9464) = 0;
  *(_BYTE *)(v5 + 9465) = 0;
  *(_BYTE *)(v5 + 9466) = 0;
  *(_BYTE *)(v5 + 352) = 0;
  *(_DWORD *)(v5 + 9460) = 2;
  if ( v11 != 512 )
    sub_6154A0(v11);
  sub_43A460((void **)&v12);
  v15[1963] = -1;
  sub_431AF0(&v14);
}
