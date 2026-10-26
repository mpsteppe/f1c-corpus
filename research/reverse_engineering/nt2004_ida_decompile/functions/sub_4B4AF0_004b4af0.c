int __thiscall sub_4B4AF0(_DWORD *this)
{
  int result; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // ebp
  int v6; // edx
  int v7; // [esp+4h] [ebp-4h]

  result = this[9];
  v7 = result;
  if ( result )
  {
    result = this[10];
    if ( result )
    {
      result = this[11];
      if ( result )
      {
        result = this[12];
        if ( result )
        {
          result = dword_75AAC4;
          if ( *(_DWORD *)(dword_75AAC4 + 4448) || *(_DWORD *)(dword_75AAC4 + 4412) )
          {
            v3 = 0;
            v4 = 0;
            v5 = 0;
            switch ( sub_4B2D40() )
            {
              case 0:
                goto LABEL_11;
              case 1:
                goto LABEL_10;
              case 2:
                goto LABEL_9;
              case 3:
                v5 = 1;
LABEL_9:
                v4 = 1;
LABEL_10:
                v3 = 1;
LABEL_11:
                v6 = 1;
                break;
              default:
                break;
            }
            sub_4B5AB0(v6, v7);
            sub_4B5AB0(v3, this[10]);
            sub_4B5AB0(v4, this[11]);
            return sub_4B5AB0(v5, this[12]);
          }
        }
      }
    }
  }
  return result;
}
