int __cdecl sub_51126A(_DWORD *a1)
{
  int v2; // eax
  char v3; // al
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int result; // eax
  char v8; // [esp-4h] [ebp-10h]

  while ( 1 )
  {
    if ( !a1[94] && !(*(_BYTE *)(a1[100] + 80) ? BitstreamTokenReader(a1) : JPEGMarkerReader(a1)) )
      return 0;
    v2 = a1[94];
    if ( v2 > 207 )
      break;
    if ( v2 >= 205 )
      goto LABEL_26;
    if ( v2 > 200 )
    {
      v4 = v2 - 201;
      if ( v4 )
      {
        v5 = v4 - 1;
        if ( v5 )
        {
          v6 = v5 - 1;
          if ( !v6 )
          {
LABEL_26:
            *(_DWORD *)(*a1 + 20) = 59;
LABEL_34:
            *(_DWORD *)(*a1 + 24) = a1[94];
            (*(void (__cdecl **)(_DWORD *))*a1)(a1);
            goto LABEL_48;
          }
          if ( v6 != 1 )
            goto LABEL_33;
          v3 = sub_510975(a1);
        }
        else
        {
          v3 = ImageFormatStreamDecoder(1, (int)a1, 1);
        }
        goto LABEL_47;
      }
      v8 = 1;
    }
    else
    {
      if ( v2 >= 197 )
        goto LABEL_26;
      if ( v2 == 1 )
      {
LABEL_36:
        *(_DWORD *)(*a1 + 20) = 91;
        *(_DWORD *)(*a1 + 24) = a1[94];
        (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
        goto LABEL_48;
      }
      if ( v2 <= 191 )
        goto LABEL_33;
      if ( v2 > 193 )
      {
        if ( v2 == 194 )
        {
          v3 = ImageFormatStreamDecoder(1, (int)a1, 0);
        }
        else
        {
          if ( v2 == 195 )
            goto LABEL_26;
          v3 = sub_510ACC(a1);
        }
        goto LABEL_47;
      }
      v8 = 0;
    }
    v3 = ImageFormatStreamDecoder(0, (int)a1, v8);
LABEL_47:
    if ( !v3 )
      return 0;
LABEL_48:
    a1[94] = 0;
  }
  if ( v2 > 219 )
  {
    if ( v2 == 220 )
    {
      v3 = StreamingDataReader(a1);
    }
    else if ( v2 == 221 )
    {
      v3 = StreamRead2ByteTokenParser((int)a1);
    }
    else
    {
      if ( v2 <= 223 )
        goto LABEL_33;
      if ( v2 <= 239 )
      {
        v3 = (*(int (__cdecl **)(_DWORD *))(a1[100] + 4 * v2 - 880))(a1);
      }
      else
      {
        if ( v2 != 254 )
        {
LABEL_33:
          *(_DWORD *)(*a1 + 20) = 67;
          goto LABEL_34;
        }
        v3 = (*(int (__cdecl **)(_DWORD *))(a1[100] + 12))(a1);
      }
    }
    goto LABEL_47;
  }
  if ( v2 == 219 )
  {
    v3 = MP3HuffmanDecoder(a1);
    goto LABEL_47;
  }
  if ( v2 <= 215 )
    goto LABEL_36;
  if ( v2 == 216 )
  {
    v3 = sub_50FF84((int)a1);
    goto LABEL_47;
  }
  if ( v2 == 217 )
  {
    *(_DWORD *)(*a1 + 20) = 84;
    (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 1);
    result = 2;
    goto LABEL_51;
  }
  if ( sub_51030D(a1) )
  {
    result = 1;
LABEL_51:
    a1[94] = 0;
    return result;
  }
  return 0;
}

