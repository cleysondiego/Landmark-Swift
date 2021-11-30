//
//  LandmarksApp.swift
//  Landmarks
//
//  Created by Cleyson Silva on 22/11/21.
//

import SwiftUI

@main
struct LandmarksApp: App {
    @StateObject private var modelData = ModelData()

    var body: some Scene {
        WindowGroup {
            ContentView()
                .environmentObject(modelData)
        }
    }
}
