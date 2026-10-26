int __thiscall LinkedListTraversalVirtualCall(_DWORD *this)
{
  int v2; // ecx
  int *v3; // eax
  int v4; // esi
  int v5; // ecx

  StateResetConditionalVirtualCall();
  v2 = this[92];
  if ( v2 >= 0 && v2 < this[63] )
  {
    v3 = (int *)this[60];
    if ( v2 <= 0 )
    {
LABEL_6:
      if ( v3 )
      {
        v4 = *v3;
        if ( *v3 )
        {
          if ( BoundsCheckWithPositionQuery(this, *v3) )
          {
            v5 = *(_DWORD *)(v4 + 48);
            if ( v5 )
              return (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 144))(v5);
          }
        }
      }
    }
    else
    {
      while ( v3 )
      {
        v3 = (int *)v3[1];
        if ( --v2 <= 0 )
          goto LABEL_6;
      }
    }
  }
  return 0;
}

