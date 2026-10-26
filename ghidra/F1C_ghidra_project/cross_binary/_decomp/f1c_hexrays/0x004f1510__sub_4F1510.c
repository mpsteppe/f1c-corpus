// f1c  0x004f1510  size=277
void __thiscall sub_4F1510(int this, float a2)
{
  double v3; // st7
  int v4; // eax
  int v5; // ecx
  int i; // ecx
  int v7; // eax
  double v8; // st7
  float *v9; // eax
  int v10; // ecx
  float *v11; // eax
  double v12; // st7
  double v13; // st7
  float v14; // [esp+0h] [ebp-8h]
  float v15; // [esp+4h] [ebp-4h]

  v3 = a2 / *(float *)(this + 15348);
  v4 = this + 13852;
  v5 = 4;
  v14 = v3;
  do
  {
    v4 += 248;
    --v5;
    *(float *)(v4 - 248) = v14 * *(float *)(v4 - 248);
  }
  while ( v5 );
  if ( (byte_7D01C4 & 1) != 0 )
  {
    sub_5881F0(v14);
    for ( i = 0; i < *(_DWORD *)(this + 14768); v9[1] = (v8 + v9[1]) * v14 - *v9 )
    {
      v7 = *(_DWORD *)(this + 14756);
      v8 = *(float *)(v7 + 8 * i);
      v9 = (float *)(v7 + 8 * i++);
    }
  }
  if ( (byte_7D01C4 & 2) != 0 )
  {
    sub_5881F0(v14);
    v10 = 1;
    if ( *(int *)(this + 14840) >= 1 )
    {
      v11 = (float *)(this + 14800);
      do
      {
        v15 = 1.0 / v14;
        v12 = v15;
        if ( ++v10 == 9 )
        {
          v13 = v12 * v11[917];
          v11 += 918;
        }
        else
        {
          v13 = v12 * *v11++;
        }
        *(v11 - 1) = v13;
      }
      while ( v10 <= *(_DWORD *)(this + 14840) );
    }
  }
  if ( (byte_7D01C4 & 4) != 0 )
  {
    sub_5881F0(v14);
    *(float *)(this + 14724) = v14 * *(float *)(this + 14724);
  }
  *(float *)(this + 15348) = a2;
  sub_4E8010(this, 0);
}
