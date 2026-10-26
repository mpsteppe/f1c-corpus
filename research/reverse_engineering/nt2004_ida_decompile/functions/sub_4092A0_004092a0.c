void __thiscall sub_4092A0(int **this)
{
  int *v2; // ebx
  int *v3; // eax
  bool v4; // zf
  int *v5; // edi
  const char *v6; // eax
  long double v7; // st4
  int *v8; // eax
  int *v9; // eax
  float v10; // [esp+Ch] [ebp-28h]
  float v11; // [esp+Ch] [ebp-28h]
  float v12; // [esp+10h] [ebp-24h] BYREF
  float v13; // [esp+14h] [ebp-20h]
  float v14; // [esp+18h] [ebp-1Ch]
  float v15; // [esp+1Ch] [ebp-18h] BYREF
  float v16; // [esp+20h] [ebp-14h]
  float v17; // [esp+24h] [ebp-10h]
  _BYTE v18[12]; // [esp+28h] [ebp-Ch] BYREF

  if ( this[4] )
  {
    sub_50C600(&v12, v18);
    sub_459C30(&v15);
    v10 = sqrt((v14 - v17) * (v14 - v17) + (v13 - v16) * (v13 - v16) + (v12 - v15) * (v12 - v15));
    if ( sub_459C40(this[4]) < v10 )
    {
      v2 = 0;
      v11 = 9999999.0;
      sub_50C600(&v15, v18);
      v3 = *this;
      v4 = *this == 0;
      this[2] = *this;
      if ( !v4 )
      {
        v5 = (int *)*v3;
        if ( *v3 )
        {
          do
          {
            v6 = (const char *)sub_459BA0(v5);
            if ( !_strcmpi(v6, aTrackside) && !(unsigned __int8)sub_459C70(v5) )
            {
              sub_459C30(&v12);
              v7 = sqrt((v17 - v14) * (v17 - v14) + (v16 - v13) * (v16 - v13) + (v15 - v12) * (v15 - v12));
              if ( v7 < v11 )
              {
                v11 = v7;
                v2 = v5;
              }
            }
            v8 = this[2];
            if ( !v8 )
              break;
            v9 = (int *)v8[1];
            this[2] = v9;
            if ( !v9 )
              break;
            v5 = (int *)*v9;
          }
          while ( *v9 );
          if ( v2 && v2 != this[4] )
          {
            if ( (unsigned __int8)sub_40A7D0(v2) )
            {
              this[19] = 0;
              this[20] = 0;
              this[21] = 0;
              this[22] = 0;
            }
          }
        }
      }
    }
  }
}
