char __thiscall sub_4D3610(_DWORD *this, int a2, int a3, int a4, float a5)
{
  char result; // al
  int v7; // ebp
  int v8; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // edi
  int v14; // ebp
  int *v15; // edx
  int v16; // edx
  int v17; // eax
  const CHAR *v18; // eax
  int v19; // eax
  const CHAR *v20; // ecx
  const CHAR *v21; // eax
  const CHAR *v22; // eax
  int v23; // [esp+4h] [ebp-4h]
  float v24; // [esp+4h] [ebp-4h]
  int v25; // [esp+10h] [ebp+8h]
  int v26; // [esp+14h] [ebp+Ch]
  float v27; // [esp+18h] [ebp+10h]

  result = a2;
  if ( a2 )
  {
    v7 = *(_DWORD *)(a2 + 40);
    v8 = this[74] + this[76];
    v23 = v7;
    v9 = a3;
    if ( LOBYTE(a5) )
      v9 = a3 - v8 * ((v7 - 1) / 2);
    v10 = v9 + v8 * v7;
    if ( v10 > 800 )
      v9 -= v8 * ((v10 - 800) / v8 + 1);
    v11 = this[3];
    if ( v9 < v11 )
    {
      v12 = (v11 - v9) / v8;
      if ( v12 >= 1 )
      {
        if ( v12 > 99 )
          v12 = 99;
      }
      else
      {
        v12 = 1;
      }
      v9 += v8 * v12;
    }
    v13 = 0;
    if ( v7 > 0 )
    {
      do
      {
        v14 = v13;
        if ( v13 >= 0 && v13 < *(_DWORD *)(a2 + 40) )
        {
          v15 = *(int **)(a2 + 28);
          if ( v13 <= 0 )
          {
LABEL_18:
            if ( v15 )
            {
              v16 = *v15;
              goto LABEL_21;
            }
          }
          else
          {
            while ( v15 )
            {
              v15 = (int *)v15[1];
              if ( --v14 <= 0 )
                goto LABEL_18;
            }
          }
        }
        v16 = 0;
LABEL_21:
        sub_4D3610(v16, v9 + v13 * (this[74] + this[76]), this[75] + a4 + this[77], COERCE_FLOAT(1));
        ++v13;
      }
      while ( v13 < v23 );
    }
    result = LOBYTE(a5);
    if ( LOBYTE(a5) )
    {
      v17 = this[61];
      v24 = (double)a3 * 0.00125;
      *(float *)&v26 = (double)a4 * 0.0016666667;
      *(float *)&v25 = (double)(int)this[74] * 0.00125;
      v27 = (double)(int)this[75] * 0.0016666667;
      if ( v17 )
      {
        v18 = *(const CHAR **)(v17 + 64);
        if ( !v18 )
          v18 = WindowName;
      }
      else
      {
        v18 = 0;
      }
      v19 = sub_4DEDE0(this[12], v18);
      if ( v19 )
      {
        v20 = (const CHAR *)this[72];
        if ( !v20 )
          v20 = WindowName;
        v21 = *(const CHAR **)(v19 + 8);
        if ( !v21 )
          v21 = WindowName;
        return sub_568830(a2 + 48, v21, this[78], v20, LODWORD(v24), v26, 0, v25, LODWORD(v27), 0, 0);
      }
      else
      {
        v22 = (const CHAR *)this[72];
        if ( !v22 )
          v22 = WindowName;
        return sub_568830(a2 + 48, 0, this[78], v22, LODWORD(v24), v26, 0, v25, LODWORD(v27), 0, 0);
      }
    }
  }
  return result;
}
