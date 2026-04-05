# HintonMarket
### COMP 3004 Winter 2026 - Deliverable 2
### Team #64

## How to Build and Run in Qt Creator

1. Extract the zip file
2. Open `HintonMarket.pro` in Qt Creator 6.0.2
3. Configure project (default kit)
4. Press Run (Ctrl+R)

## Database Setup

This project uses **Option A — Auto-copy via .pro file**.

The `hintonMarket.db` database is in the source folder next to the `.pro` file. The `.pro` has a copydb rule that copies it to the build directory automatically on first build. No manual steps needed.

If auto-copy fails, manually copy `hintonMarket.db` from the source folder to the build output directory.

## User Accounts for Testing

### Food Vendors
- haashir
- ali
- saad
- syed

### Artisan Vendors
- tanveer
- sohail
- ahmed
- dana

### Market Operator
- operator

### System Administrator
- admin

No passwords required.

## New in Deliverable 2

### SQLite Persistence
All data is stored in memory as objects AND in the SQLite database. Data persists between program restarts.

### Market Operator Features (login as "operator")
1. **Book a stall on behalf of a vendor** — Select vendor from dropdown + market date, click "Book Stall for Vendor"
2. **Cancel a stall booking on behalf of a vendor** — Select vendor, select their booking, click "Cancel Booking"
3. **Remove a vendor from a waitlist** — Select vendor, select waitlist entry, click "Remove from Waitlist"

All operator actions show up on the vendor's dashboard when the vendor logs in.