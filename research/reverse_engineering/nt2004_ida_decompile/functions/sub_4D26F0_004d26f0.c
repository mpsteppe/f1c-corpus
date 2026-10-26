int *__thiscall sub_4D26F0(int this)
{
  _BYTE *v2; // eax
  int v3; // ecx
  int *result; // eax
  int v5; // edi
  double v6; // st7
  int v7; // esi
  int **v8; // edx
  char v9; // bl
  bool v10; // zf
  int v11; // ecx
  int *v12; // eax
  float v13; // [esp+0h] [ebp-4h]

  if ( sub_405BE0(&dword_629124) )
    dword_769800 = 2;
  if ( *(_DWORD *)(this + 6400) != dword_769800 )
  {
    v2 = (_BYTE *)(this + 260);
    v3 = 256;
    do
    {
      *((_DWORD *)v2 - 1) = -1082130432;
      *v2 = 0;
      v2 += 8;
      --v3;
    }
    while ( v3 );
    *(_DWORD *)(this + 6400) = dword_769800;
    *(float *)(this + 6404) = sub_4D9E20(&unk_7D5DAC);
    dword_761FF8 = 1;
  }
  if ( *(_DWORD *)(this + 6400) == 1 )
    return (int *)sub_4D2D80(this);
  result = (int *)(*(_DWORD *)(this + 6400) - 2);
  if ( *(_DWORD *)(this + 6400) == 2 )
  {
    v5 = this;
    v13 = *(float *)(this + 6404);
    v6 = sub_4D9E20(&unk_7D5DAC);
    if ( v6 > v13 )
    {
      v7 = 0;
      v8 = (int **)(v5 + 2304);
      do
      {
        result = *v8;
        v9 = *(_BYTE *)(v7 + v5) & 1;
        v10 = *v8 == 0;
        v8[2] = *v8;
        if ( v10 || (v11 = *result) == 0 )
        {
LABEL_24:
          *(_BYTE *)(v7 + v5) = 0;
        }
        else
        {
          while ( 1 )
          {
            if ( *(float *)v11 >= (double)v13 )
            {
              if ( v6 < *(float *)v11 )
                goto LABEL_26;
              if ( *(_BYTE *)(v11 + 4) != v9 )
                break;
            }
            v12 = v8[2];
            if ( v12 )
              v8[2] = (int *)v12[1];
            result = v8[2];
            if ( result )
            {
              v11 = *result;
              if ( *result )
                continue;
            }
            goto LABEL_24;
          }
          v9 = *(_BYTE *)(v11 + 4);
LABEL_26:
          result = v9 == 0 ? 0 : (int *)0x81;
          *(_BYTE *)(v7 + v5) = (_BYTE)result;
        }
        ++v7;
        v8 += 4;
      }
      while ( v7 < 256 );
      *(float *)(v5 + 6404) = v6;
    }
    else
    {
      *(float *)(this + 6404) = v6;
      result = 0;
      memset((void *)this, 0, 0x100u);
    }
  }
  return result;
}
