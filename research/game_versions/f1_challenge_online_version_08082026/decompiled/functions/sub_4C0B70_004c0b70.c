char __thiscall sub_4C0B70(int this, _DWORD *a2)
{
  _DWORD *v2; // ebp
  char v3; // bl
  int v5; // eax
  int v6; // eax
  int v8; // edx
  int v9; // eax

  v2 = a2;
  v3 = 0;
  if ( *a2 )
  {
    while ( sub_566CC0(&unk_8AC1E8, 256) )
    {
      v3 = 1;
      v5 = sub_5651B0(&unk_8AC050);
      if ( v5 )
      {
        v6 = v5 - 1;
        if ( !v6 || v6 == 3 )
          return v3;
      }
      else
      {
        v8 = sub_587C20(&unk_8AC1E8, aOpponent);
        if ( v8 )
        {
          v9 = sub_587ECE(strlen(aOpponent) + v8);
          sub_4C03F0((_BYTE *)(this + 436 * v9), v2);
        }
        else if ( sub_587C20(&unk_8AC1E8, aPlayer) )
        {
          sub_4C03F0((_BYTE *)(this + 44908), v2);
        }
        else if ( sub_565760(aSeasonstatus, &a2, 0, 0, 0) )
        {
          *(_DWORD *)(this + 45380) = a2;
        }
        else
        {
          sub_565760(aRacesession, this + 45388, 0, 0, 0);
          if ( sub_565760(aRaceover, &a2, 0, 0, 0) )
            *(_BYTE *)(this + 45392) = a2 != 0;
          sub_565760(aCurrentrace, this + 45384, 0, 0, 0);
        }
      }
    }
  }
  return v3;
}
