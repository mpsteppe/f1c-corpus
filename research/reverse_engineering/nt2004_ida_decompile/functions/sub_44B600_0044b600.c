char __thiscall sub_44B600(_DWORD *this, _DWORD *a2)
{
  _DWORD *v3; // ebp
  int v4; // esi
  int v5; // esi
  int v6; // esi
  int v7; // eax
  float *v8; // ebx
  int v9; // eax
  int v11; // [esp+10h] [ebp-50h]
  float *v12; // [esp+14h] [ebp-4Ch]
  _BYTE v13[72]; // [esp+18h] [ebp-48h] BYREF

  sub_44B340(this, (int)v13);
  v3 = a2;
  v4 = 0;
  while ( !sub_44B400((int)v13, (float *)a2[2 * v4]) )
  {
    if ( ++v4 >= 3 )
    {
      sub_44B340(a2, (int)v13);
      v5 = 0;
      while ( !sub_44B400((int)v13, (float *)this[2 * v5]) )
      {
        if ( ++v5 >= 3 )
        {
          v6 = 0;
LABEL_9:
          if ( v6 == 2 )
            v7 = 0;
          else
            v7 = v6 + 1;
          v8 = (float *)this[2 * v7];
          v11 = 0;
          v12 = (float *)v3[2 * v6];
          while ( 1 )
          {
            v9 = v6 == 2 ? 0 : v6 + 1;
            if ( sub_44B440((float *)this[2 * v6], v8, v12, (float *)v3[2 * v9]) )
              return 1;
            if ( ++v11 >= 3 )
            {
              if ( ++v6 < 3 )
              {
                v3 = a2;
                goto LABEL_9;
              }
              return 0;
            }
            v3 = a2;
          }
        }
      }
      return 1;
    }
  }
  return 1;
}
