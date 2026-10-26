void __stdcall sub_41AB40(_DWORD *a1)
{
  int v2; // ebx
  int v3; // eax
  int v4; // edi
  int v5; // esi
  int v6; // eax
  int v7; // ebx
  BOOL v8; // ebp
  float v9; // [esp+10h] [ebp-10h] BYREF
  int v10; // [esp+14h] [ebp-Ch] BYREF
  int v11; // [esp+18h] [ebp-8h]
  int v12; // [esp+1Ch] [ebp-4h]
  char v13; // [esp+24h] [ebp+4h]
  float v14; // [esp+24h] [ebp+4h]

  if ( !dword_7688A0
    || flt_7678BC == 0.0
    || !byte_6292D8
    || sub_4633A0(&unk_764D70) == 1
    || !(unsigned __int8)sub_4EED40(a1)
    || dword_7D5DA4 == 2 )
  {
    return;
  }
  v2 = a1[5212];
  v12 = v2;
  if ( (unsigned int)dword_75CBB0 <= 6 )
  {
    if ( *(_BYTE *)(dword_75AACC + 17412) != 1 )
    {
      v14 = sub_4DD0C0(v2 - 1);
      if ( (unsigned __int8)sub_4EED40(a1) )
      {
        if ( v14 != 0.0 && dword_7D5DA4 != 2 )
          sub_419530((__int64)v14, (__int64)((v14 - (double)(int)(__int64)v14 + 0.00050000002) * 100.0));
      }
    }
  }
  else
  {
    if ( dword_75CBB0 != 7 )
      return;
    if ( !(unsigned __int8)sub_42DBA0(&unk_62BF64) )
      return;
    if ( !dword_75AACC )
      return;
    if ( *(_DWORD *)(dword_75AACC + 20892) )
      return;
    v3 = *(_DWORD *)(dword_75AACC + 20896);
    if ( v3 )
    {
      if ( v3 != 4 )
        return;
    }
    if ( (unsigned int)dword_7D7540 > 1 || dword_75CBB4 == 8 )
      return;
    v4 = a1[5221];
    v5 = dword_7D74B8 - v2;
    v11 = NumOfElements;
    if ( dword_7D74B8 - v2 == v2 || (v13 = 0, v5 == v2 - 1) )
      v13 = 1;
    v9 = 0.0;
    v10 = 0;
    if ( v5 != 1 && !v13 || (int)NumOfElements <= 1 )
      goto LABEL_29;
    if ( v4 == 1 )
    {
      sub_4B2C70(a1, a1[5254], &v9, &v10);
    }
    else
    {
      v6 = sub_4FA870(0);
      sub_4B2C70((char *)&unk_62BF68 + 25304 * v6, a1, &v9, &v10);
    }
    if ( v10 )
      v9 = flt_6290DC * (double)v10;
    if ( v9 > 1.0 )
      v7 = 1;
    else
LABEL_29:
      v7 = 0;
    v8 = v9 > 0.0 && v9 <= 1.0;
    if ( v5 == 1 )
    {
      sub_4193E0(1024, 0);
      if ( v4 == 1 )
      {
        if ( v8 )
        {
          sub_4193E0(1024, 16);
        }
        else if ( v7 )
        {
          sub_4193E0(1024, 32);
        }
      }
      else
      {
        if ( v8 )
        {
          if ( v4 == 2 )
          {
            sub_4193E0(1024, 64);
            return;
          }
          if ( v4 >= 3 && v4 <= 5 )
          {
            sub_4193E0(1024, 256);
            return;
          }
        }
        else
        {
          if ( !v7 )
            return;
          if ( v4 == 2 )
          {
            sub_4193E0(1024, 128);
            return;
          }
          if ( v4 >= 3 && v4 <= 5 )
          {
            sub_4193E0(1024, 512);
            return;
          }
        }
        if ( v4 >= 6 && v4 <= 10 )
          sub_4193E0(1024, 1024);
      }
    }
    else
    {
      if ( v13 )
      {
        sub_4193E0(32, 0);
        if ( v4 == 1 )
        {
          if ( v11 > 1 )
          {
            sub_4193E0(32, 1);
            return;
          }
        }
        else if ( v4 > 5 )
        {
          if ( v4 > 10 )
          {
            if ( v4 > (int)(NumOfElements - 15) )
              sub_4193E0(32, 8);
          }
          else
          {
            sub_4193E0(32, 4);
          }
          return;
        }
        sub_4193E0(32, 2);
        return;
      }
      switch ( v5 )
      {
        case 20:
          sub_4193E0(64, 0);
          break;
        case 10:
          sub_4193E0(128, 0);
          break;
        case 5:
          sub_4193E0(256, 0);
          break;
        case 2:
          sub_4193E0(512, 0);
          break;
        default:
          switch ( v12 )
          {
            case 50:
              sub_4193E0(1, 0);
              break;
            case 100:
              sub_4193E0(2, 0);
              break;
            case 200:
              sub_4193E0(4, 0);
              break;
            case 300:
              sub_4193E0(8, 0);
              break;
            case 400:
              sub_4193E0(16, 0);
              break;
          }
          break;
      }
    }
  }
}
