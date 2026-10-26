int __thiscall sub_4A3910(int this, const char *a2)
{
  const char *v3; // ecx
  char *v4; // eax
  char *v5; // eax
  int v6; // eax
  char v7; // cl
  int v8; // ecx
  int v9; // eax
  char v10; // cl
  int v11; // ecx
  int v12; // ecx
  float v14; // [esp+0h] [ebp-28h]
  _BYTE v15[16]; // [esp+18h] [ebp-10h] BYREF

  v3 = a2;
  *(_WORD *)this = 0;
  sub_4A21D0((__int16 *)this, v3, aPitguycMts, 0, dword_7CF884 >= 1);
  sub_4A3B50(this);
  v4 = (char *)dword_5EC3D8;
  if ( !dword_5EC3D8 )
    v4 = byte_5EA438;
  sub_566650(v4);
  v5 = (char *)dword_5EC420;
  if ( !dword_5EC420 )
    v5 = byte_5EA438;
  sub_5665B0(v5);
  sub_5665B0(aPits_0);
  if ( byte_5EA3EC )
    sub_5665B0(aLeft);
  else
    sub_5665B0(aNormal_0);
  sub_53C800(byte_5EA438);
  a2 = 0;
  sub_53CBC0(&a2, aPitanimsMas);
  v6 = 0;
  do
  {
    v7 = byte_5CD4A4[v6];
    v15[v6++] = v7;
  }
  while ( v7 );
  sub_566650(v15);
  sub_5665B0(aAnm);
  sub_4A22D0((_DWORD *)this, (int)v15, (int)byte_5EA438, 0, 0);
  if ( *(int *)(this + 112) > 0 )
  {
    sub_4A1FD0(*(float **)(this + 116), 0.0, *(float *)(*(_DWORD *)(this + 116) + 16));
    *(_DWORD *)(this + 124) = *(_DWORD *)(v8 + 4);
  }
  v9 = 0;
  do
  {
    v10 = byte_5CD490[v9];
    v15[v9++] = v10;
  }
  while ( v10 );
  sub_566650(v15);
  sub_5665B0(aAnm);
  sub_4A22D0((_DWORD *)this, (int)v15, (int)byte_5EA438, 0, 0);
  if ( *(int *)(this + 112) > 1 )
  {
    v11 = *(_DWORD *)(this + 116);
    v14 = *(float *)(v11 + 44) + *(float *)(this + 124);
    sub_4A1FD0((float *)(v11 + 28), *(float *)(this + 124), v14);
    *(_DWORD *)(this + 128) = *(_DWORD *)(v12 + 4);
  }
  if ( a2 )
    sub_53CE40(a2);
  sub_53C900(byte_5EA438);
  sub_4A3FE0(this);
  return 0;
}
