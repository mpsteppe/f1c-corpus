// f1c  0x0043e230  size=289
_DWORD *__thiscall sub_43E230(int this)
{
  int v2; // edi
  double *v3; // ebp
  int v4; // esi
  double *v5; // ebx
  int v6; // ecx
  _DWORD *result; // eax
  _DWORD *v8; // edi
  int v9; // esi
  int v10; // [esp+0h] [ebp-18h]
  float v11; // [esp+0h] [ebp-18h]
  float v12; // [esp+0h] [ebp-18h]
  float v13; // [esp+0h] [ebp-18h]

  *(float *)&v10 = *(double *)(this + 7500);
  sub_431A50((int)&byte_7C56C0, v10);
  v2 = 0;
  v3 = (double *)(this + 1720);
  do
  {
    v11 = *(v3 - 5);
    sub_431930((float *)&byte_7C56C0, v2, v11);
    v12 = *v3;
    sub_4319C0((float *)&byte_7C56C0, v2, v12);
    v4 = 0;
    v5 = v3 - 28;
    do
    {
      v13 = *v5;
      sub_431A70((float *)&byte_7C56C0, v2, v4++, v13);
      ++v5;
    }
    while ( v4 < 3 );
    ++v2;
    v3 = (double *)((char *)v3 + 1124);
  }
  while ( v2 < 4 );
  sub_4D5840(&dword_8AD238);
  sub_4358F0((_DWORD *)(this + 492));
  *(_DWORD *)(this + 7936) = 0;
  sub_56E970(this + 5548);
  if ( *(_DWORD *)(this + 7420) )
    sub_587BCF(*(LPVOID *)(this + 7420));
  if ( *(_DWORD *)(this + 5676) )
    sub_587BCF(*(LPVOID *)(this + 5676));
  memset((void *)this, 0, 0x1F38u);
  v6 = 0;
  result = (_DWORD *)(this + 1496);
  do
  {
    *(result - 181) = v6;
    *result = -1889785610;
    result[1] = 1081507266;
    v8 = result + 2;
    result[2] = *result;
    result[3] = result[1];
    result[4] = result[2];
    v9 = result[3];
    ++v6;
    result += 281;
    v8[3] = v9;
  }
  while ( v6 < 4 );
  return result;
}
