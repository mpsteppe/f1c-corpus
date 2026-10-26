int __thiscall sub_647AE9(int *this, int a2)
{
  int *v2; // esi
  int v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // edi
  bool v6; // zf
  int v7; // eax
  int v8; // ecx
  int v10; // [esp-4h] [ebp-288h]
  _DWORD v11[33]; // [esp+Ch] [ebp-278h] BYREF
  char v12[64]; // [esp+90h] [ebp-1F4h] BYREF
  ULONG_PTR Parameter[12]; // [esp+D0h] [ebp-1B4h] BYREF
  double v14; // [esp+100h] [ebp-184h]
  char v15; // [esp+250h] [ebp-34h] BYREF
  void *(__stdcall *v16)(int); // [esp+258h] [ebp-2Ch]
  int (__stdcall *v17)(DWORD); // [esp+25Ch] [ebp-28h]
  int (__stdcall *v18)(DWORD); // [esp+260h] [ebp-24h]
  int v19; // [esp+264h] [ebp-20h]
  void *v20; // [esp+268h] [ebp-1Ch]
  int v21; // [esp+26Ch] [ebp-18h]
  int *v22; // [esp+270h] [ebp-14h]
  int v23; // [esp+274h] [ebp-10h]
  unsigned int v24; // [esp+278h] [ebp-Ch]
  unsigned int v25; // [esp+27Ch] [ebp-8h]
  void *Block; // [esp+280h] [ebp-4h] BYREF

  v10 = *this;
  v22 = this;
  v23 = 0;
  Block = 0;
  v19 = a2;
  v20 = 0;
  v16 = sub_647A64;
  v17 = sub_647A8C;
  v18 = sub_647AC0;
  v21 = sub_644568(v10)[2] >> 3;
  sub_6792D0((ULONG_PTR)Parameter, 62, 384);
  Parameter[0] = sub_679270(v11);
  v11[0] = sub_647778;
  v11[2] = nullsub_10;
  if ( _setjmp3(v12, 0) )
  {
    v23 = -2147467259;
  }
  else
  {
    Parameter[10] = 2;
    sub_679D60(Parameter);
    v2 = v22;
    v14 = 2.2;
    Parameter[7] = v22[3];
    Parameter[8] = v22[4];
    Parameter[6] = (ULONG_PTR)&v15;
    Parameter[9] = 3;
    sub_6794E0(Parameter, 1);
    Block = operator new(3 * v2[3]);
    if ( Block )
    {
      v3 = v2[12];
      v4 = v2[1] + v21 * v2[6] + v3 * v2[7];
      v5 = v4 + v3 * v2[4];
      while ( 1 )
      {
        v24 = v4;
        if ( v4 >= v5 )
          break;
        v6 = v2[3] == 0;
        v25 = 0;
        if ( !v6 )
        {
          v7 = 0;
          do
          {
            v8 = *(_DWORD *)(v24 + 4 * v25);
            *((_BYTE *)Block + v7) = BYTE2(v8);
            ++v25;
            *((_BYTE *)Block + v7 + 1) = BYTE1(v8);
            *((_BYTE *)Block + v7 + 2) = v8;
            v7 += 3;
          }
          while ( v25 < v2[3] );
        }
        sub_679550(Parameter, &Block, 1);
        v4 = v2[12] + v24;
      }
      sub_679400(Parameter);
      sub_6775B0(Parameter);
    }
    else
    {
      v23 = -2147024882;
    }
  }
  j__free(Block);
  j__free(v20);
  return v23;
}
