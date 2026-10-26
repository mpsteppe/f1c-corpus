int __fastcall sub_473E40(char *Destination, int a2)
{
  int result; // eax
  unsigned int v4; // kr04_4
  signed int v5; // esi
  char v6; // bl
  int v7; // eax
  char Source[125]; // [esp+Ch] [ebp-80h] BYREF
  __int16 v10; // [esp+89h] [ebp-3h]
  char v11; // [esp+8Bh] [ebp-1h]

  Source[0] = byte_629120;
  result = 0;
  memset(&Source[1], 0, 0x7Cu);
  v10 = 0;
  v11 = 0;
  if ( Destination )
  {
    if ( a2 > 1 )
    {
      result = 0;
      v4 = strlen(Destination) + 1;
      if ( (int)(v4 - 1) > 0 )
      {
        v5 = 0;
        do
        {
          if ( result >= 127 )
            break;
          v6 = Destination[v5];
          if ( v6 == 46 )
          {
            Source[result] = 32;
            v7 = result + 1;
            Source[v7++] = 100;
            Source[v7++] = 111;
            Source[v7] = 116;
            result = v7 + 1;
            Source[result] = 32;
          }
          else
          {
            Source[result] = v6;
          }
          ++result;
          ++v5;
        }
        while ( v5 < (int)(v4 - 1) );
        Source[result] = 0;
        result = (int)strncpy(Destination, Source, a2 - 1);
        Destination[a2 - 1] = 0;
      }
    }
  }
  return result;
}
