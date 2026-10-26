void __stdcall sub_41A500(float a1)
{
  double v1; // st7
  double v2; // st7
  int v3; // esi
  float v4; // [esp+4h] [ebp-24h]
  float v5[8]; // [esp+8h] [ebp-20h] BYREF
  float v6; // [esp+2Ch] [ebp+4h]

  if ( dword_7D0308 )
  {
    if ( flt_7CF3C8 != 0.0 )
    {
      v1 = a1 - dbl_8AFEA0;
      v6 = v1;
      if ( v1 < 2700.0 )
      {
        v2 = dbl_8AFE98 + v6;
        v4 = v2;
        if ( v2 >= 2700.0 )
        {
          v3 = 35;
LABEL_6:
          StructInitWithSentinelValues(v5);
          CommentaryEventQueue(v5, v3, -1, -1, -1, -1, -2.0, -2.0);
          InsertDriverTableEntry(flt_5EA618, v5);
          return;
        }
        if ( v6 < 1800.0 )
        {
          if ( v4 >= 1800.0 )
          {
            v3 = 34;
            goto LABEL_6;
          }
          if ( v6 < 900.0 )
          {
            if ( v4 >= 900.0 )
            {
              v3 = 277;
              goto LABEL_6;
            }
            if ( v6 < 600.0 )
            {
              if ( v4 >= 600.0 )
              {
                v3 = 276;
                goto LABEL_6;
              }
              if ( v6 < 300.0 )
              {
                if ( v4 >= 300.0 )
                {
                  v3 = 279;
                  goto LABEL_6;
                }
                if ( v6 < 180.0 )
                {
                  if ( v4 >= 180.0 )
                  {
                    v3 = 278;
                    goto LABEL_6;
                  }
                  if ( v6 <= 0.0 )
                  {
                    if ( dword_5EB10C )
                      (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
                    BufferInitWith10fDefaults(flt_5EA618);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

