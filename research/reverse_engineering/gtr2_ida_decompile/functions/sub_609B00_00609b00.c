char __thiscall sub_609B00(int this, int a2, int a3)
{
  char v3; // bl
  int v5; // eax

  v3 = 0;
  switch ( a2 )
  {
    case 1:
      v5 = a3;
      if ( *(_DWORD *)(this + 204) != a3 )
      {
        *(_DWORD *)(this + 204) = a3;
        goto LABEL_14;
      }
      break;
    case 2:
      v5 = a3;
      if ( *(_DWORD *)(this + 208) != a3 )
      {
        *(_DWORD *)(this + 208) = a3;
        goto LABEL_14;
      }
      break;
    case 3:
      v5 = a3;
      if ( *(_DWORD *)(this + 212) != a3 )
      {
        *(_DWORD *)(this + 212) = a3;
        goto LABEL_14;
      }
      break;
    case 4:
      v5 = a3;
      if ( *(_DWORD *)(this + 220) != a3 )
      {
        *(_DWORD *)(this + 220) = a3;
        goto LABEL_14;
      }
      break;
    case 5:
      v5 = a3;
      if ( *(_DWORD *)(this + 224) != a3 )
      {
        *(_DWORD *)(this + 224) = a3;
        goto LABEL_14;
      }
      break;
    case 6:
      v5 = a3;
      if ( *(_DWORD *)(this + 228) != a3 )
      {
        *(_DWORD *)(this + 228) = a3;
LABEL_14:
        v3 = 1;
        if ( *(_BYTE *)(this + 236) )
          (*(void (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)dword_FB40C8 + 268))(
            dword_FB40C8,
            *(_DWORD *)(this + 240),
            a2,
            v5);
      }
      break;
    default:
      return v3 & *(_BYTE *)(this + 236);
  }
  return v3 & *(_BYTE *)(this + 236);
}
