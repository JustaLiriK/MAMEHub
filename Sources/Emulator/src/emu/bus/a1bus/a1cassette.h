/*********************************************************************

    a1cassette.h

    Apple II 6850 MIDI card, as made by Passport, Yamaha, and others.

*********************************************************************/

#ifndef __A1BUS_CASSETTE__
#define __A1BUS_CASSETTE__

#include "a1bus.h"
#include "imagedev/cassette.h"

//**************************************************************************
//  TYPE DEFINITIONS
//**************************************************************************

class a1bus_cassette_device:
	public device_t,
	public device_a1bus_card_interface
{
public:
	// construction/destruction
	a1bus_cassette_device(const machine_config &mconfig, const char *tag, device_t *owner, UINT32 clock);
	a1bus_cassette_device(const machine_config &mconfig, device_type type, const char *name, const char *tag, device_t *owner, UINT32 clock, const char *shortname, const char *source);

	// optional information overrides
	virtual machine_config_constructor device_mconfig_additions() const;
	virtual const rom_entry *device_rom_region() const;

	optional_device<cassette_image_device> m_cassette;

	DECLARE_READ8_MEMBER(cassette_r);
	DECLARE_WRITE8_MEMBER(cassette_w);

protected:
	virtual void device_start();
	virtual void device_reset();

	void cassette_toggle_output();

private:
	UINT8 *m_rom;
	int m_cassette_output_flipflop;
};

// device type definition
extern const device_type A1BUS_CASSETTE;

#endif  /* __A1BUS_CASSETTE__ */
