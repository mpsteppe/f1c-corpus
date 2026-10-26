void __thiscall sub_460F00(int this, float a2)
{
  int v3; // eax
  double v4; // st7
  int v5; // ecx
  int *v6; // ebp
  int v7; // edi
  double v8; // st7
  int v9; // ecx
  double v10; // st7
  int v11; // edi
  double v12; // st7
  long double v13; // st7
  long double v14; // st6
  double v15; // st7
  float v16; // [esp+0h] [ebp-144h]
  int v17; // [esp+0h] [ebp-144h]
  float v18; // [esp+4h] [ebp-140h]
  int v19; // [esp+8h] [ebp-13Ch]
  float v20; // [esp+18h] [ebp-12Ch] BYREF
  long double v21; // [esp+1Ch] [ebp-128h]
  char *v22; // [esp+24h] [ebp-120h] BYREF
  char v23[4]; // [esp+28h] [ebp-11Ch] BYREF
  long double v24; // [esp+2Ch] [ebp-118h] BYREF
  char Buffer[64]; // [esp+34h] [ebp-110h] BYREF
  char v26[8]; // [esp+74h] [ebp-D0h] BYREF
  __int16 v27; // [esp+7Ch] [ebp-C8h]

  v3 = *(_DWORD *)(this + 6720);
  if ( v3 == 2 || v3 == 1 )
  {
    v4 = a2 + *(float *)(this + 660);
    *(float *)(this + 660) = v4;
    if ( v4 > 5.0 )
    {
      v5 = *(_DWORD *)(this + 6512);
      *(_DWORD *)(this + 660) = 0;
      LODWORD(v21) = 0;
      if ( v5 > 0 )
      {
        v6 = (int *)(this + 6320);
        v7 = this + 752;
        do
        {
          if ( !(unsigned __int8)sub_462C60(1)
            && (unsigned __int8)sub_462C60(2)
            && sub_45DFA0((unsigned __int8 *)(this + 27716), *(char *)(v7 + 100), (float *)&v24, COERCE_FLOAT(1)) )
          {
            v16 = dbl_7DA9D0;
            sub_4D0D00(4, 51, 2, 63, LODWORD(v16), 0);
            v8 = *(float *)&v24;
            if ( *(float *)&v24 >= -5.0 )
            {
              if ( *(float *)&v24 > 5.0 )
                v8 = 5.0;
            }
            else
            {
              v8 = -5.0;
            }
            v17 = *v6;
            v27 = (__int64)(v8 / 0.00025000001 + 0.5);
            sub_463A40(v26, 2, v17, -1);
          }
          v9 = *(_DWORD *)(this + 6512);
          ++v6;
          v7 += 116;
          ++LODWORD(v21);
        }
        while ( SLODWORD(v21) < v9 );
      }
    }
  }
  else
  {
    v10 = *(float *)(this + 16) - a2;
    *(float *)(this + 16) = v10;
    if ( v10 < 0.0 )
    {
      *(float *)&v19 = dbl_7DA9D0;
      sub_45FD90(this, v19);
      *(_DWORD *)(this + 16) = *(_DWORD *)(this + 12);
    }
    if ( (unsigned __int8)sub_56A340(&v20, &v22, v23) )
    {
      v11 = *v22;
      if ( dword_75CBB0 != v11 && v11 < 9 )
      {
        *(_BYTE *)(this + 636) = 1;
        if ( !byte_76617C )
          sub_4B9460(&byte_766124);
        sub_42F6C0(&dword_75CBA8, v11);
        sub_4BA660(&unk_76612C);
        *(_DWORD *)(this + 16) = 0x40000000;
      }
      v21 = v20;
      v12 = sub_527940(&unk_7DA938);
      v13 = v21 - v12;
      v14 = fabs(v13);
      if ( v14 <= 1.0 )
      {
        if ( v14 <= 0.5 )
        {
          *(long double *)(this + 668) = v13;
          return;
        }
        *(_DWORD *)(this + 668) = 0;
        if ( v13 <= 0.0 )
        {
          *(_DWORD *)(this + 672) = -1075838976;
          v21 = v13 + 0.5;
          v15 = v20 + 0.5;
        }
        else
        {
          *(_DWORD *)(this + 672) = 1071644672;
          v21 = v13 - 0.5;
          v15 = v20 - 0.5;
        }
        v18 = v15;
        sub_5279A0(v18, 0);
        v24 = v21 * 1000.0;
        LODWORD(v21) = (int)v24;
        if ( sub_41F230(dword_62A170, aSynchronizingG, Destination) )
        {
          strncpy(Destination, aSynchronizingG, 0x1FFu);
          byte_62A37B = 0;
        }
        sub_405480(Buffer, 0x3Fu, "%s (%d ms)", Destination, LODWORD(v21));
      }
      else
      {
        sub_42DD60(v20);
        sub_5279A0(v20, 0);
        *(_DWORD *)(this + 668) = 0;
        *(_DWORD *)(this + 672) = 0;
        if ( sub_41F230(dword_62A170, aSynchronizingG, Destination) )
        {
          strncpy(Destination, aSynchronizingG, 0x1FFu);
          byte_62A37B = 0;
        }
        sub_405480(Buffer, 0x3Fu, "%s", Destination);
      }
      sub_45D100(&byte_764D68, (int)Buffer, 3, 16909060, 0);
    }
  }
}
