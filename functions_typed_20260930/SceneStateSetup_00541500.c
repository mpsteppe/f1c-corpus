int __thiscall sub_541500(int *this, int a2)
{
  int result; // eax
  int v4; // edx
  int v5; // eax
  int v6; // eax
  _DWORD v7[26]; // [esp+10h] [ebp-68h] BYREF

  if ( !this[1270] )
    return 0;
  memset(v7, 0, sizeof(v7));
  if ( a2 == 1 )
  {
    v7[0] = 3;
    v7[19] = 1399379109;
  }
  else if ( a2 == 2 || a2 == 4 )
  {
    v7[0] = 1;
    *(float *)&v7[19] = sqrt(3.402823466385289e38);
  }
  v7[18] = 0;
  memset(&v7[13], 0, 16);
  v4 = this[1261];
  v5 = this[1088];
  memset(&v7[9], 0, 12);
  v7[1] = 1065353216;
  v7[2] = 1065353216;
  v7[3] = 1065353216;
  v7[5] = 1065353216;
  v7[6] = 1065353216;
  v7[7] = 1065353216;
  v7[17] = -1082130432;
  v7[21] = 1065353216;
  v7[22] = 0;
  v7[23] = 0;
  v6 = (*(int (__stdcall **)(int, int, _DWORD *))(*(_DWORD *)v5 + 176))(v5, v4, v7);
  *this = v6;
  if ( v6 )
    return -1;
  result = this[1261];
  this[1261] = result + 1;
  return result;
}

