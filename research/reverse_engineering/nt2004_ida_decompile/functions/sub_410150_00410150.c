char __thiscall sub_410150(int this, int a2, unsigned __int8 a3)
{
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  char *v11; // eax
  int v12; // eax
  const char *v13; // eax
  _DWORD *v14; // eax
  int v15; // ebx
  signed int v16; // ebx
  int v17; // edi
  int v18; // eax
  _DWORD *v19; // esi
  char *v20; // eax
  _DWORD *v21; // esi
  int v23; // [esp+10h] [ebp-88h]
  signed int v24; // [esp+10h] [ebp-88h]
  int v25; // [esp+14h] [ebp-84h]
  char Destination[125]; // [esp+18h] [ebp-80h] BYREF
  __int16 v27; // [esp+95h] [ebp-3h]
  char v28; // [esp+97h] [ebp-1h]

  v25 = 0;
  (**(void (__thiscall ***)(int))dword_76BB24)(dword_76BB24);
  v4 = sub_57AE50(aReputationmain);
  v5 = v4;
  if ( v4 )
  {
    v6 = sub_40C570(v4, *(unsigned __int8 *)(this + 8));
    v23 = v6;
    if ( v6 >= 0 )
    {
      v7 = sub_57A700(v6);
      v8 = (char *)sub_57A6D0(v7);
      if ( !sub_40C4D0(v8, a3) )
      {
        v9 = 0;
        if ( sub_57A6E0(v5) > 0 )
        {
          while ( 1 )
          {
            v10 = sub_57A700(v9);
            v11 = (char *)sub_57A6D0(v10);
            if ( sub_40C4D0(v11, a3) )
              break;
            if ( ++v9 >= sub_57A6E0(v5) )
              goto LABEL_11;
          }
          if ( v9 >= 0 )
          {
            (**(void (__thiscall ***)(int))dword_76BB24)(dword_76BB24);
            v12 = sub_57AE50(aReputationchan);
            if ( v12 )
            {
              v13 = (const char *)sub_57A6D0(v12);
              v25 = (v9 - v23) * atoi(v13);
            }
          }
        }
      }
    }
  }
LABEL_11:
  LOBYTE(v14) = *(_BYTE *)(this + 8);
  v15 = *(unsigned __int8 *)(this + 9);
  *(_BYTE *)(this + 9) = 0;
  v16 = (unsigned __int8)v14 + v25 + v15;
  if ( v16 >= 0 )
  {
    if ( v16 > 100 )
      v16 = 100;
  }
  else
  {
    v16 = 0;
  }
  *(_BYTE *)(this + 8) = v16;
  v24 = (unsigned __int8)v14;
  if ( (unsigned __int8)v14 == v16 || !v5 )
    return (char)v14;
  Destination[0] = byte_629120;
  memset(&Destination[1], 0, 0x7Cu);
  v27 = 0;
  v28 = 0;
  v17 = sub_40C570(v5, (unsigned __int8)v14);
  v18 = sub_40C570(v5, v16);
  if ( v17 == v18 )
  {
    if ( v24 < v16 )
    {
      LOBYTE(v14) = sub_410970(aRepbettersameb, Destination, 128);
      if ( !(_BYTE)v14 )
        return (char)v14;
      v14 = operator new(8u);
      v19 = v14;
      if ( v14 )
        goto LABEL_21;
      goto LABEL_22;
    }
    v20 = aRepworsesameba;
  }
  else
  {
    if ( v17 < v18 )
    {
      LOBYTE(v14) = sub_410970(aRepbetterhighe, Destination, 128);
      if ( !(_BYTE)v14 )
        return (char)v14;
      v14 = operator new(8u);
      v19 = v14;
      if ( v14 )
      {
LABEL_21:
        *v14 = 0;
        v14[1] = -1;
        LOBYTE(v14) = sub_578600(Destination);
        goto LABEL_23;
      }
LABEL_22:
      v19 = 0;
LABEL_23:
      if ( v19 )
      {
        v14 = operator new(0xCu);
        if ( v14 )
        {
          *v14 = v19;
          v14[1] = 0;
          *((_BYTE *)v14 + 8) = 1;
        }
        else
        {
          v14 = 0;
        }
        if ( *(_DWORD *)(this + 132) )
        {
          *(_DWORD *)(*(_DWORD *)(this + 136) + 4) = v14;
        }
        else
        {
          *(_DWORD *)(this + 132) = v14;
          *(_DWORD *)(this + 140) = v14;
        }
LABEL_47:
        *(_DWORD *)(this + 136) = v14;
        ++*(_DWORD *)(this + 144);
        return (char)v14;
      }
      return (char)v14;
    }
    v20 = aRepworselowerb;
  }
  LOBYTE(v14) = sub_410970(v20, Destination, 128);
  if ( (_BYTE)v14 )
  {
    v14 = operator new(8u);
    v21 = v14;
    if ( v14 )
    {
      *v14 = 0;
      v14[1] = -1;
      LOBYTE(v14) = sub_578600(Destination);
    }
    else
    {
      v21 = 0;
    }
    if ( v21 )
    {
      v14 = operator new(0xCu);
      if ( v14 )
      {
        *v14 = v21;
        v14[1] = 0;
        *((_BYTE *)v14 + 8) = 1;
      }
      else
      {
        v14 = 0;
      }
      if ( *(_DWORD *)(this + 132) )
      {
        *(_DWORD *)(*(_DWORD *)(this + 136) + 4) = v14;
      }
      else
      {
        *(_DWORD *)(this + 132) = v14;
        *(_DWORD *)(this + 140) = v14;
      }
      goto LABEL_47;
    }
  }
  return (char)v14;
}
