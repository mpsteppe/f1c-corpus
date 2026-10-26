int __thiscall sub_5B3B20(void *this, char *FileName, _DWORD *a3)
{
  FILE *v5; // edi
  int v6; // ebp
  const char *v7; // esi
  size_t v8; // esi
  char Buffer[256]; // [esp+10h] [ebp-A14h] BYREF
  char v11[256]; // [esp+110h] [ebp-914h] BYREF
  _DWORD v12[2]; // [esp+210h] [ebp-814h] BYREF
  size_t ElementCount; // [esp+218h] [ebp-80Ch]
  void *v14; // [esp+A20h] [ebp-4h]

  sub_5B19E0(v12);
  if ( *FileName )
  {
    v5 = fopen(FileName, aRb);
    if ( v5 )
      goto LABEL_10;
    v6 = 0;
    if ( dword_7E8D58 > 0 )
    {
      v7 = byte_7E4CCC;
      do
      {
        sprintf(v11, "%s\\%s", v7, FileName);
        v5 = fopen(v11, aRb);
        if ( v5 )
          break;
        ++v6;
        v7 += 132;
      }
      while ( v6 < dword_7E8D58 );
    }
    if ( v6 != dword_7E8D58 )
    {
LABEL_10:
      fseek(v5, 0, 2);
      v8 = ftell(v5);
      fseek(v5, 0, 0);
      ElementCount = v8;
      v14 = operator new(v8);
      if ( sub_5BED6F(v14, 1u, ElementCount, v5) == v8 && sub_5B1A10(v12) != 3 )
      {
        do
        {
          if ( v12[0] == 3 )
            break;
          if ( v12[0] != 2 && sub_5B1DC0((int)v12, aInstance, Buffer, 0) && sub_5B1A10(v12) != 3 )
          {
            while ( v12[0] != 3 )
            {
              if ( v12[0] != 2 && sub_5B1DC0((int)v12, aMeshfile, Buffer, 0) )
              {
                if ( a3 )
                  ++*a3;
                break;
              }
              if ( sub_5B1A10(v12) == 3 )
                break;
            }
          }
        }
        while ( sub_5B1A10(v12) != 3 );
      }
      sub_5BE8AE();
      fclose(v5);
      return 0;
    }
    else
    {
      sprintf(Buffer, "Illegal scene file name %s", FileName);
      sub_591C60((int)this, -1, Buffer);
      return -1;
    }
  }
  else
  {
    sprintf(Buffer, "Illegal scene file name %s", FileName);
    sub_591C60((int)this, -1, Buffer);
    return -1;
  }
}
