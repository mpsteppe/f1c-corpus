char __thiscall sub_413ED0(_BYTE *this, _DWORD *a2)
{
  char result; // al
  int v4; // ebp
  int v5; // edi
  int v6; // eax
  unsigned __int8 v7; // al
  void *v8; // eax
  char v9; // cl
  unsigned __int8 v10; // al
  int v11; // ecx
  unsigned __int8 v12; // al
  void *v13; // eax
  char v14; // cl
  unsigned __int8 v15; // al
  int v16; // ecx
  int v17; // [esp+8h] [ebp-31Ch] BYREF
  _BYTE v18[384]; // [esp+Ch] [ebp-318h] BYREF
  int v19; // [esp+18Ch] [ebp-198h]
  char v20; // [esp+190h] [ebp-194h]
  int v21; // [esp+198h] [ebp-18Ch]
  int v22; // [esp+19Ch] [ebp-188h]
  int v23; // [esp+1A0h] [ebp-184h]
  char Buffer[384]; // [esp+1A4h] [ebp-180h] BYREF

  result = 0;
  if ( *a2 )
  {
    memset(Buffer, 0, sizeof(Buffer));
    v19 = 0;
    v23 = 0;
    v21 = 0;
    v22 = 0;
    v20 = 1;
    v4 = 0;
    v5 = 0;
    while ( sub_57A490(Buffer, 383) )
    {
      v6 = sub_577B60(v18);
      if ( v6 )
      {
        if ( v6 == 2 || v6 == 4 )
          return 1;
      }
      else if ( sub_578110(aYear, (int)&v17, 0, 0, 0) )
      {
        *(_WORD *)this = v17;
      }
      else if ( sub_578110(aNumraces, (int)&v17, 0, 0, 0) )
      {
        this[2] = v17;
      }
      else if ( sub_578110(aPoints, (int)&v17, 0, 0, 0) )
      {
        *((_DWORD *)this + 3) = v17;
      }
      else if ( sub_578110(aStanding, (int)&v17, 0, 0, 0) )
      {
        this[16] = v17;
      }
      else if ( sub_578110(aEarnings, (int)&v17, 0, 0, 0) )
      {
        *((_DWORD *)this + 5) = v17;
      }
      else if ( sub_578110(aLapsled, (int)&v17, 0, 0, 0) )
      {
        *((_DWORD *)this + 6) = v17;
      }
      else if ( sub_578110(aQualifyingpos, (int)&v17, 0, 0, 0) && (v7 = this[2]) != 0 )
      {
        if ( !*((_DWORD *)this + 1) )
        {
          v8 = operator new(v7);
          v9 = this[2];
          *((_DWORD *)this + 1) = v8;
          v10 = 0;
          if ( v9 )
          {
            do
            {
              v11 = v10++;
              *(_BYTE *)(v11 + *((_DWORD *)this + 1)) = -1;
            }
            while ( v10 < this[2] );
          }
        }
        *(_BYTE *)(*((_DWORD *)this + 1) + v4++) = v17;
      }
      else if ( sub_578110(aFinishpos, (int)&v17, 0, 0, 0) )
      {
        v12 = this[2];
        if ( v12 )
        {
          if ( !*((_DWORD *)this + 2) )
          {
            v13 = operator new(v12);
            v14 = this[2];
            *((_DWORD *)this + 2) = v13;
            v15 = 0;
            if ( v14 )
            {
              do
              {
                v16 = v15++;
                *(_BYTE *)(v16 + *((_DWORD *)this + 2)) = -1;
              }
              while ( v15 < this[2] );
            }
          }
          *(_BYTE *)(v5 + *((_DWORD *)this + 2)) = v17;
          ++v5;
        }
      }
    }
    return 1;
  }
  return result;
}
