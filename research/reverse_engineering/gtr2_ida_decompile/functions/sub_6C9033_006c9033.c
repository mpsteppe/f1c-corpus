int __thiscall sub_6C9033(int *this)
{
  unsigned int v1; // ebx
  unsigned int v3; // eax
  bool v4; // zf
  int result; // eax
  int v6; // ecx
  int v7; // edx
  unsigned int v8; // ecx
  _DWORD *v9; // edx
  bool v10; // cf
  int v11; // edi
  unsigned int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ebx
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // ebx
  bool v22; // cc
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // edx
  int v27; // ecx
  int v28; // eax
  int v29; // ecx
  _BYTE v30[128]; // [esp+14h] [ebp-10Ch] BYREF
  _BYTE v31[128]; // [esp+94h] [ebp-8Ch] BYREF
  int v32; // [esp+114h] [ebp-Ch] BYREF
  unsigned int v33; // [esp+118h] [ebp-8h]
  int v34; // [esp+11Ch] [ebp-4h] BYREF

  v1 = 0;
  v3 = 0;
  v4 = this[2] == 0;
  v32 = 0;
  if ( !v4 )
  {
    do
    {
      *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v3) + 48) = -1;
      *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v3++) + 52) = -1;
    }
    while ( v3 < this[2] );
  }
  v33 = this[3];
  result = sub_6C47A3(this, 0x1FFFFFFFFLL, (unsigned int *)&v32, 0, 0, 0, v33, (char *)1, 0, 0, 0);
  if ( this[2] )
  {
    do
    {
      v6 = 4 * v1;
      v7 = 4 * v1 + this[5];
      if ( *(_DWORD *)(*(_DWORD *)v7 + 48) != -1 || *(_DWORD *)(*(_DWORD *)v7 + 52) != -1 )
      {
        *(_DWORD *)(*(_DWORD *)v7 + 20) = *(_DWORD *)(*(_DWORD *)v7 + 48);
        *(_DWORD *)(*(_DWORD *)(v6 + this[5]) + 24) = *(_DWORD *)(*(_DWORD *)(v6 + this[5]) + 52);
      }
      *(_DWORD *)(*(_DWORD *)(v6 + this[5]) + 48) = -1;
      *(_DWORD *)(*(_DWORD *)(v6 + this[5]) + 52) = -1;
      ++v1;
    }
    while ( v1 < this[2] );
  }
  v8 = 0;
  if ( v33 )
  {
    do
    {
      v9 = *(_DWORD **)(this[6] + 4 * v8++);
      v10 = v8 < v33;
      *v9 = 0;
    }
    while ( v10 );
  }
  if ( result >= 0 )
  {
    this[63] = 0;
    sub_6C36BC(this, (int)v30, (int)v31, 0, 0);
    v4 = this[3] == 0;
    v33 = 0;
    if ( !v4 )
    {
      do
      {
        v11 = *(_DWORD *)(this[6] + 4 * v33);
        v12 = *(_DWORD *)v11 & 0xFFF00000;
        if ( (*(_DWORD *)v11 & 0xFFFFF) == 1 )
        {
          v32 = -1;
          v34 = -1;
          switch ( v12 )
          {
            case 0x73000000u:
            case 0x73200000u:
            case 0x73100000u:
            case 0x73300000u:
              v28 = *(_DWORD *)(this[5] + 4 * **(_DWORD **)(v11 + 8));
              v29 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v28 + 4)) + 4);
              if ( (v29 & 0x200) != 0 && (v29 & 0x2000) == 0 )
              {
                result = sub_6C38CA((int)this, (int)"b", 0x2000, v28, &v32);
                if ( result < 0 )
                  return result;
                **(_DWORD **)(v11 + 8) = v32;
              }
              break;
            case 0x73B00000u:
              v13 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v11 + 8) + 4));
              if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v13 + 4)) + 5) & 1) != 0
                && *(_DWORD *)(v13 + 8) == -1
                && *(double *)(v13 + 32) == 0.0 )
              {
                v14 = sub_681AAA(this, 0, 0, 0, 0.0);
                v34 = v14;
                if ( v14 == -1 )
                  return -2147024882;
                v15 = this[5];
                v16 = *(_DWORD *)(v15 + 4 * v14);
                v32 = *(_DWORD *)(v15 + 4 * **(_DWORD **)(v11 + 8));
                result = sub_6815D6((double *)v16, v32);
                if ( result < 0 )
                  return result;
                result = sub_681692((_DWORD *)v16, (_DWORD *)v32);
                if ( result < 0 )
                  return result;
                *(_DWORD *)(v16 + 60) ^= 0x80000u;
                v17 = v34;
                *(_DWORD *)(v16 + 56) = **(_DWORD **)(v11 + 8);
                *(_DWORD *)(*(_DWORD *)(v11 + 8) + 4) = v17;
              }
              break;
            case 0x74200000u:
            case 0x74100000u:
              v18 = *(_DWORD *)(this[5] + 4 * **(_DWORD **)(v11 + 8));
              v19 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * *(_DWORD *)(v18 + 4)) + 4);
              if ( (v19 & 0x200) != 0 && (v19 & 0x40000) == 0 )
              {
                result = sub_6C38CA((int)this, (int)&unk_739B00, 0x40000, v18, &v34);
                if ( result < 0 )
                  return result;
                v20 = v34;
                **(_DWORD **)(v11 + 8) = v34;
                v21 = *(_DWORD *)(this[5] + 4 * v20);
                v22 = *(_DWORD *)(v11 + 4) <= 1u;
                v34 = 1;
                if ( !v22 )
                {
                  do
                  {
                    v23 = *(_DWORD *)(*(_DWORD *)(v11 + 8) + 4 * v34);
                    if ( v23 == -1 )
                      v24 = v21;
                    else
                      v24 = *(_DWORD *)(this[5] + 4 * v23);
                    v25 = sub_681AAA(this, *(_DWORD *)(v21 + 4), *(_DWORD *)(v21 + 12), v34, *(double *)(v24 + 32));
                    v26 = v34;
                    v27 = *(_DWORD *)(v11 + 8);
                    ++v34;
                    *(_DWORD *)(v27 + 4 * v26) = v25;
                  }
                  while ( (unsigned int)v34 < *(_DWORD *)(v11 + 4) );
                }
              }
              break;
          }
        }
        ++v33;
      }
      while ( v33 < this[3] );
    }
    result = sub_688BDF(this);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
