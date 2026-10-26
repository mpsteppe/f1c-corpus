int __thiscall sub_681D0E(_DWORD *this, _DWORD *a2)
{
  int v3; // ebx
  int v4; // eax
  void *v5; // eax
  int v6; // eax
  void *v7; // eax
  int v8; // ebx
  int v9; // eax
  void *v10; // eax
  int v11; // ebx

  v3 = 0;
  this[1] = 0;
  v4 = a2[1];
  this[7] = v4;
  v5 = operator new(4 * v4);
  this[4] = v5;
  if ( v5 )
  {
    if ( a2[1] )
    {
      while ( sub_681B61(this, *(_DWORD *)(a2[4] + 4 * v3)) != -1 )
      {
        if ( (unsigned int)++v3 >= a2[1] )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      this[2] = 0;
      v6 = a2[2];
      this[8] = v6;
      v7 = operator new(4 * v6);
      v8 = 0;
      this[5] = v7;
      if ( v7 )
      {
        if ( a2[2] )
        {
          while ( sub_681BB1(this, *(_DWORD *)(a2[5] + 4 * v8)) != -1 )
          {
            if ( (unsigned int)++v8 >= a2[2] )
              goto LABEL_9;
          }
        }
        else
        {
LABEL_9:
          this[3] = 0;
          v9 = a2[3];
          this[9] = v9;
          v10 = operator new(4 * v9);
          v11 = 0;
          this[6] = v10;
          if ( v10 )
          {
            if ( !a2[3] )
              return 0;
            while ( sub_681C03(this, *(_DWORD **)(a2[6] + 4 * v11)) != -1 )
            {
              if ( (unsigned int)++v11 >= a2[3] )
                return 0;
            }
          }
        }
      }
    }
  }
  return -2147024882;
}
