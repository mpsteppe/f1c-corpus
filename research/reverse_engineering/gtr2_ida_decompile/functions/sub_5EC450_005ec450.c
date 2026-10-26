int __thiscall sub_5EC450(int *this, int a2)
{
  _BYTE *v2; // eax
  bool v3; // zf
  int *v4; // eax
  float *v5; // edi
  float *v6; // edx
  char v7; // bl
  int v8; // ebp
  int v9; // esi
  int result; // eax
  int v11; // eax
  int v12; // [esp+10h] [ebp-8h]
  float v13; // [esp+1Ch] [ebp+4h]

  v2 = (_BYTE *)this[98];
  *this &= 0xFFFFFFF0;
  v3 = (*v2 & 0x10) == 0;
  v4 = this + 30;
  if ( v3 )
    v4 = this + 6;
  v12 = 0;
  if ( this[62] <= 0 )
  {
    v8 = a2;
    goto LABEL_19;
  }
  v5 = (float *)(a2 + 252);
  while ( 2 )
  {
    v6 = (float *)(v4 + 1);
    v7 = 0;
    v8 = 0;
    v9 = 0;
    while ( 1 )
    {
      v13 = -v5[2];
      if ( v6[1] * v5[1] + *(v6 - 1) * *(v5 - 1) + *v5 * *v6 <= v13 )
        break;
      ++v8;
      v7 = 1;
LABEL_9:
      ++v9;
      v6 += 3;
      if ( v9 >= 8 )
        goto LABEL_12;
    }
    if ( !v7 )
      goto LABEL_9;
    *this |= 2u;
LABEL_12:
    if ( !v8 )
    {
      v5 += 4;
      if ( ++v12 >= this[62] )
      {
        result = *this | 1;
        *this = result;
        return result;
      }
      continue;
    }
    break;
  }
  v11 = *this;
  if ( v8 == 8 )
  {
    result = v11 | 4;
    *this = result;
    return result;
  }
  *this = v11 | 2;
LABEL_19:
  if ( !v8 )
    *this |= 1u;
  return *this;
}
