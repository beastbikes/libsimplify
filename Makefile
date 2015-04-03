all: debug release 

debug: simplify.xcodeproj
	@xcodebuild -target All -configuration Debug -project simplify.xcodeproj
release: simplify.xcodeproj
	@xcodebuild -target All -configuration Release -project simplify.xcodeproj

simplify.xcodeproj:
	@gyp --depth=. simplify.gyp

clean:
	@xcodebuild -project simplify.xcodeproj clean

