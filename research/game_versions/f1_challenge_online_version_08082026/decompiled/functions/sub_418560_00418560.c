char __thiscall sub_418560(float *this, float *a2)
{
  char result; // al
  int v4; // ebp
  int v5; // esi
  int v6; // edx
  float *v7; // ecx
  int v8; // ebx
  float *v9; // ecx
  int v10; // esi
  float *v11; // ebx
  float *v12; // ecx
  int v13; // ebx
  float *v14; // esi
  int v15; // [esp-4h] [ebp-20h]
  char *v16; // [esp+10h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-4h]

  result = 0;
  if ( *(_DWORD *)a2 != -1 )
  {
    if ( !(unsigned __int8)sub_418B90(*(_DWORD *)a2) )
      return 0;
    v15 = *(_DWORD *)a2;
    *((_DWORD *)a2 + 1) = dword_5BF9B0[5 * *(_DWORD *)a2];
    v4 = -1;
    v5 = 0;
    v17 = sub_418B70(v15);
    *((_DWORD *)a2 + 7) = v17;
    v6 = 0;
    v16 = 0;
    v7 = this + 539;
    do
    {
      v8 = *((_DWORD *)v7 + 5);
      if ( v8 <= *(_DWORD *)((char *)this + (_DWORD)v16 + 2176) )
      {
        v5 = v6;
        v16 = (char *)v7 - 2156 - (_DWORD)this;
      }
      if ( v4 < 0 && (*(_DWORD *)v7 == -1082130432 || a2[2] < (double)*v7 || a2[2] == *v7 && v17 > v8) )
        v4 = v6;
      ++v6;
      v7 += 8;
    }
    while ( v6 < 20 );
    if ( v4 >= 0 )
    {
      if ( v5 <= v4 )
      {
        if ( v5 < v4 && v5 < --v4 )
        {
          v12 = &this[8 * v5 + 537];
          v13 = v4 - v5;
          do
          {
            v14 = v12 + 8;
            sub_4145C0(v12, (_DWORD *)v12 + 8);
            --v13;
            v12 = v14;
          }
          while ( v13 );
        }
      }
      else
      {
        v9 = &this[8 * v5 + 537];
        v10 = v5 - v4;
        do
        {
          v11 = v9 - 8;
          sub_4145C0(v9, (_DWORD *)v9 - 8);
          --v10;
          v9 = v11;
        }
        while ( v10 );
      }
      sub_4145C0(&this[8 * v4 + 537], a2);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
