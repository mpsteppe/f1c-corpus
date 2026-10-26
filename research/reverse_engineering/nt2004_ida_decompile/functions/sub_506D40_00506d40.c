void __thiscall sub_506D40(
        float *this,
        char *Source,
        int a3,
        int a4,
        int a5,
        _DWORD *a6,
        float a7,
        float a8,
        CHAR *a9,
        char a10)
{
  int v11; // esi
  int v12; // edi
  int v13; // ebx
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // ecx
  int v18; // eax
  signed int v19; // edx
  int v20; // eax
  char v21; // cl
  char *v22; // eax
  int v23; // edx
  char v24; // cl
  int v25; // edx
  int v26; // [esp-4h] [ebp-154h]
  char v27; // [esp+13h] [ebp-13Dh]
  int v28; // [esp+14h] [ebp-13Ch] BYREF
  int v29; // [esp+18h] [ebp-138h] BYREF
  int v30; // [esp+1Ch] [ebp-134h] BYREF
  int v31; // [esp+20h] [ebp-130h] BYREF
  int v32; // [esp+24h] [ebp-12Ch]
  int v33; // [esp+28h] [ebp-128h] BYREF
  int v34; // [esp+2Ch] [ebp-124h] BYREF
  int v35; // [esp+30h] [ebp-120h] BYREF
  int v36; // [esp+34h] [ebp-11Ch] BYREF
  int v37; // [esp+38h] [ebp-118h] BYREF
  _BYTE v38[13]; // [esp+3Ch] [ebp-114h] BYREF
  __int16 v39; // [esp+49h] [ebp-107h]
  char v40; // [esp+4Bh] [ebp-105h]
  int v41; // [esp+4Ch] [ebp-104h] BYREF
  char Destination[125]; // [esp+50h] [ebp-100h] BYREF
  __int16 v43; // [esp+CDh] [ebp-83h]
  char v44; // [esp+CFh] [ebp-81h]
  _BYTE v45[125]; // [esp+D0h] [ebp-80h] BYREF
  __int16 v46; // [esp+14Dh] [ebp-3h]
  char v47; // [esp+14Fh] [ebp-1h]
  int v48; // [esp+158h] [ebp+8h]
  int v49; // [esp+15Ch] [ebp+Ch]

  if ( Source )
  {
    Destination[0] = byte_629120;
    memset(&Destination[1], 0, 0x7Cu);
    v43 = 0;
    v44 = 0;
    if ( !a9 )
    {
      a9 = (CHAR *)*((_DWORD *)this + 10);
      if ( !a9 )
        a9 = &byte_629120;
    }
    if ( a7 > 0.0 )
      this[14] = a7;
    if ( a8 > 0.0 )
      this[15] = a8;
    strncpy(Destination, Source, 0x7Fu);
    v44 = 0;
    sub_506B70(this, &v30, &v31, 0);
    sub_506B50(this, &v28, &v29);
    v28 += v30;
    v32 = v31 + v29;
    v48 = v30 + a3;
    v49 = v31 + a4;
    if ( Destination[0] )
    {
      while ( 1 )
      {
        sub_505C10((int)a9, (int)Destination, &v33, &v36, *((_DWORD *)this + 14), *((_DWORD *)this + 15));
        v11 = v36;
        v12 = v33;
        sub_5058A0(v48, v49, v33, v36, a6, &v37, &v35);
        v13 = v37;
        v29 = v37 + v12;
        v14 = v35 + v11;
        if ( v35 < v31 || (v27 = 1, v14 > v32) )
          v27 = 0;
        if ( v37 >= v30 && v29 <= v28 && (!a10 || v27) )
          break;
        if ( a10 && (v35 < v31 || v14 > v32) || v12 <= 0 )
          return;
        *(_DWORD *)&v38[5] = 0;
        *(_DWORD *)&v38[9] = 0;
        strcpy(v38, "AbCd");
        v15 = *((_DWORD *)this + 15);
        v39 = 0;
        v26 = v15;
        v16 = *((_DWORD *)this + 14);
        v40 = 0;
        sub_505C10((int)a9, (int)v38, &v34, &v41, v16, v15);
        v17 = v34 / 4;
        if ( v34 / 4 >= 1 )
        {
          if ( v17 > 1000 )
            v17 = 1000;
        }
        else
        {
          v17 = 1;
        }
        if ( v13 >= v30 )
        {
          v25 = (v29 - v28) / v17;
          if ( v25 >= 1 )
          {
            if ( v25 > 1000 )
              v25 = 1000;
          }
          else
          {
            v25 = 1;
          }
          if ( v25 >= (int)strlen(Destination) )
            return;
          Destination[strlen(Destination) - v25] = 0;
        }
        else
        {
          v18 = (v30 - v13) / v17;
          v19 = v18;
          if ( v18 >= 1 )
          {
            if ( v18 > 1000 )
              v19 = 1000;
          }
          else
          {
            v19 = 1;
          }
          if ( v19 >= (int)strlen(Destination) )
            return;
          v45[0] = byte_629120;
          memset(&v45[1], 0, 0x7Cu);
          v46 = 0;
          v47 = 0;
          v20 = 0;
          do
          {
            v21 = Destination[v20];
            v45[v20++] = v21;
          }
          while ( v21 );
          v22 = &v45[v19];
          v23 = Destination - &v45[v19];
          do
          {
            v24 = *v22;
            v22[v23] = *v22;
            ++v22;
          }
          while ( v24 );
        }
        if ( !Destination[0] )
          return;
      }
      sub_505C90((int)a9, (int)Destination, v48, v49, a5, (int)a6, *((_DWORD *)this + 14), *((_DWORD *)this + 15), 0);
    }
  }
}
