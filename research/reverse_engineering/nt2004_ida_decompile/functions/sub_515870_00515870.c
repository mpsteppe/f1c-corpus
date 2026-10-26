void __thiscall sub_515870(float *this)
{
  unsigned __int8 v3; // c0
  unsigned __int8 v4; // c2
  int v5; // ebp
  float *v6; // eax
  float *v7; // ebx
  int v8; // ecx
  int v9; // edx
  int v10; // edi
  float *v11; // edi
  int v12; // ecx
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c2
  int v16; // edx
  unsigned __int8 v18; // c0
  unsigned __int8 v19; // c2
  int v20; // ecx
  float *v21; // eax
  int v22; // edx
  int v23; // ebp
  int v24; // eax
  int v25; // ecx
  int v26; // [esp+10h] [ebp-44h]
  int v27; // [esp+14h] [ebp-40h]
  float v28; // [esp+18h] [ebp-3Ch] BYREF
  int v29; // [esp+24h] [ebp-30h] BYREF
  int v30; // [esp+30h] [ebp-24h] BYREF
  _DWORD v31[3]; // [esp+3Ch] [ebp-18h] BYREF
  _DWORD v32[3]; // [esp+48h] [ebp-Ch] BYREF

  if ( sub_4DD160((_DWORD *)(*(_DWORD *)this + 20836), 1) )
  {
    sub_51C1E0(&v29, v31);
    sub_4F8F50(*(_DWORD **)this, &v30, v32);
    if ( !(v3 | v4) )
    {
      v5 = 2 * dword_6290C4;
      v26 = 2 * dword_6290C4;
      v6 = sub_403D10(&flt_628F60, this + 4380, 0);
      *((_DWORD *)this + 4750) = v6;
      v7 = v6;
      v8 = *(_DWORD *)(*(_DWORD *)this + 20852);
      v9 = 0;
      if ( *((_DWORD *)v6 + 28) != v8 )
      {
        do
        {
          v5 = v26;
          v7 = (float *)*((_DWORD *)v7 + 73);
          v10 = v9++;
          if ( v10 > v26 )
            return;
        }
        while ( *((_DWORD *)v7 + 28) != v8 );
      }
      sub_4F8F50(*(_DWORD **)this, &v29, v31);
      sub_51BD20(&v30, v32, &v28);
      v11 = sub_403D10(&flt_628F60, &v28, 0);
      v12 = 0;
      if ( v14 | v15 )
      {
        do
        {
          v11 = (float *)*((_DWORD *)v11 + 73);
          v16 = v12++;
          if ( v16 > v5 )
            return;
        }
        while ( v18 | v19 );
      }
      v20 = 0;
      if ( *((_BYTE *)this + 17328) )
      {
        v21 = v7;
        while ( v21 != v11 )
        {
          if ( *((_DWORD *)v21 + 82) )
          {
            v21 = (float *)*((_DWORD *)v21 + 74);
            v22 = v20++;
            if ( v22 <= v26 )
              continue;
          }
          return;
        }
      }
      this[4383] = *(float *)v31;
      this[4384] = *(float *)&v31[1];
      this[4385] = *(float *)&v31[2];
      sub_579100(this + 4383, this + 4371);
      v23 = 1;
      v27 = 0;
      while ( 1 )
      {
        this[4380] = *v7;
        this[4381] = v7[1];
        this[4382] = v7[2];
        sub_514EB0((int)this);
        *(_DWORD *)(*(_DWORD *)this + 20952) = 1;
        sub_5155D0(this, 0);
        sub_5157A0(this);
        sub_5A1290(0x8000000);
        if ( dword_7D78E4 )
        {
          sub_5A12F0(1);
          sub_5A0F50(dword_7D78E4, 1);
          sub_5A12F0(0);
        }
        if ( dword_7D78E8 )
        {
          sub_5A12F0(1);
          sub_5A0F50(dword_7D78E8, 1);
          sub_5A12F0(0);
        }
        if ( dword_7D78EC )
        {
          sub_5A12F0(1);
          sub_5A0F50(dword_7D78EC, 1);
          sub_5A12F0(0);
        }
        if ( v23 != 1 )
          break;
        if ( v7 == v11 )
          v23 = 2;
        v24 = *((_DWORD *)v7 + 75);
        if ( !v24 || *(_DWORD *)(v24 + 328) != 1 )
          goto LABEL_29;
        v7 = (float *)*((_DWORD *)v7 + 75);
LABEL_30:
        v25 = v27++;
        if ( v25 > v26 )
        {
LABEL_31:
          sub_5A1290(0x8000000);
          return;
        }
      }
      if ( !*((_DWORD *)v7 + 28) )
        goto LABEL_31;
LABEL_29:
      v7 = (float *)*((_DWORD *)v7 + 74);
      goto LABEL_30;
    }
  }
}
