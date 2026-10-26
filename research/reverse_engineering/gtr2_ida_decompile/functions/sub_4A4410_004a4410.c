_DWORD *__thiscall sub_4A4410(_DWORD *this, int a2)
{
  _DWORD *result; // eax
  bool v4; // zf
  bool v5; // cc

  sub_4D9E90();
  v4 = a2 == dword_16C9B40;
  v5 = a2 <= dword_16C9B40;
  *this = &off_6FE728;
  this[72] = a2;
  this[69] = 0;
  this[70] = 0;
  *((_BYTE *)this + 284) = 0;
  if ( v5 )
  {
    if ( v4 )
    {
      this[70] = &byte_B71908;
      return this;
    }
    else if ( a2 > 455 )
    {
      switch ( a2 )
      {
        case 470:
          this[70] = &unk_B6CCD0;
          result = this;
          break;
        case 502:
          this[69] = &dword_B71E40;
          result = this;
          break;
        case 631:
          this[70] = &byte_B71D20;
          result = this;
          break;
        case 646:
          this[70] = &byte_B71C18;
          result = this;
          break;
        case 647:
          this[70] = &byte_B71C00;
          result = this;
          break;
        case 679:
          this[70] = &byte_B6FAB4;
          result = this;
          break;
        case 680:
          goto LABEL_66;
        case 681:
          this[70] = &unk_B6FAE4;
          result = this;
          break;
        case 682:
          this[70] = &unk_B72D6C;
          result = this;
          break;
        case 683:
          this[70] = &unk_B72D84;
          result = this;
          break;
        case 684:
          this[70] = &byte_B718D8;
          result = this;
          break;
        case 685:
          this[70] = &byte_B722FC;
          result = this;
          break;
        case 686:
          this[70] = &byte_B71950;
          result = this;
          break;
        case 687:
          this[70] = &byte_B71E10;
          result = this;
          break;
        default:
          goto LABEL_75;
      }
    }
    else if ( a2 == 455 )
    {
      this[69] = &dword_B71E64;
      return this;
    }
    else if ( a2 > 420 )
    {
      switch ( a2 )
      {
        case 431:
          this[69] = &dword_B70E64;
          result = this;
          break;
        case 444:
          this[70] = &byte_B702B8;
          result = this;
          break;
        case 445:
          this[69] = &unk_B7051C;
          result = this;
          break;
        case 446:
          this[69] = &dword_B70564;
          result = this;
          break;
        case 447:
          this[69] = &dword_B70588;
          result = this;
          break;
        case 452:
          this[70] = &byte_B71BE8;
          result = this;
          break;
        default:
          goto LABEL_75;
      }
    }
    else if ( a2 == 420 )
    {
      this[69] = &unk_B70E1C;
      return this;
    }
    else
    {
      if ( a2 > 299 )
      {
        switch ( a2 )
        {
          case 300:
            this[69] = &dword_B72188;
            return this;
          case 301:
            this[69] = &dword_B721D0;
            return this;
          case 302:
            this[69] = &dword_B71F00;
            return this;
        }
      }
      else
      {
        switch ( a2 )
        {
          case 299:
            this[69] = &dword_B7108C;
            return this;
          case 30:
            this[70] = &unk_B7327C;
            return this;
          case 193:
            this[70] = &byte_B729E8;
            return this;
          case 194:
            this[70] = &byte_B73264;
            return this;
        }
      }
LABEL_75:
      this[69] = 0;
      return this;
    }
  }
  else
  {
    switch ( a2 )
    {
      case 689:
        this[70] = &byte_B71920;
        result = this;
        break;
      case 690:
        this[70] = &byte_B7117C;
        result = this;
        break;
      case 692:
        this[70] = &unk_B6CCD1;
        result = this;
        break;
      case 693:
        this[70] = &byte_B7360C;
        result = this;
        break;
      case 694:
        this[70] = &byte_B7345C;
        result = this;
        break;
      case 695:
        this[70] = &byte_B73528;
        result = this;
        break;
      case 696:
        this[70] = &byte_B73570;
        result = this;
        break;
      case 697:
        this[70] = &byte_B71EE8;
        result = this;
        break;
      case 698:
        this[70] = &byte_B71968;
        result = this;
        break;
      case 699:
        this[70] = &byte_B73A08;
        result = this;
        break;
      case 700:
        this[70] = &byte_B71980;
        result = this;
        break;
      case 701:
        this[70] = &byte_B71194;
        result = this;
        break;
      case 702:
        this[70] = &byte_B708D0;
        result = this;
        break;
      case 704:
        this[70] = &unk_BE1D4C;
        result = this;
        break;
      case 827:
        this[70] = &byte_B73990;
        result = this;
        break;
      case 828:
        this[70] = &byte_B739A8;
        result = this;
        break;
      case 829:
        this[70] = &byte_B739C0;
        result = this;
        break;
      case 830:
        this[70] = &byte_B739D8;
        result = this;
        break;
      case 831:
        this[70] = &byte_B724C0;
        result = this;
        break;
      case 832:
        this[70] = &byte_B71B1C;
        result = this;
        break;
      case 833:
LABEL_66:
        this[70] = &byte_B6FACC;
        result = this;
        break;
      case 834:
        this[70] = &byte_B72D3C;
        result = this;
        break;
      case 835:
        this[70] = &byte_B731B0;
        result = this;
        break;
      case 836:
        this[69] = &dword_B6FCAC;
        result = this;
        break;
      case 837:
        this[70] = &byte_B72218;
        result = this;
        break;
      case 854:
        this[70] = &byte_B731C8;
        result = this;
        break;
      case 855:
        this[70] = &byte_B731E0;
        result = this;
        break;
      case 856:
        this[70] = &byte_B731F8;
        result = this;
        break;
      default:
        goto LABEL_75;
    }
  }
  return result;
}
